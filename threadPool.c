#include "threadPool.h"

//free the memory allocated to the program.
void FreeMemory(ThreadPool *threadPool) {
    if (threadPool) {
        //queue is freed
        if (threadPool->queue) {
            while (!osIsQueueEmpty(threadPool->queue)) {
                Mission *mission = osDequeue(threadPool->queue);
                free(mission);
            }
            osDestroyQueue(threadPool->queue);
        }
        //threads are freed
        if (threadPool->threads) {
            free(threadPool->threads);
        }
        //thread pool is freed
        free(threadPool);
    }
}

//Handle a failure of a system call.
void OnFailure(ThreadPool *threadPool) {
    //write error to stderr
    write(2, SYS_CALL_ERROR, strlen(SYS_CALL_ERROR));
    //free any allocated memory
    FreeMemory(threadPool);
    //exit he program.
    _exit(EXIT_FAILURE);
}

//Initialize the locks, return value is if succeeded or failed.
int InitLocks(ThreadPool *pool) {
    if (pthread_mutex_init(&(pool->lockMission), NULL) != SYS_CALL_SUCCESS) {
        return SYS_CALL_FAIL;
    }
    if (pthread_mutex_init(&(pool->lockDestroy), NULL) != SYS_CALL_SUCCESS) {
        return SYS_CALL_FAIL;
    }
    if (pthread_mutex_init(&(pool->lockQueue), NULL) != SYS_CALL_SUCCESS) {
        return SYS_CALL_FAIL;
    }
    if (pthread_cond_init(&(pool->notify), NULL) != SYS_CALL_SUCCESS) {
        return SYS_CALL_FAIL;
    }
    return SYS_CALL_SUCCESS;
}

//Destroy the locks, return value is if succeeded or failed.
int DestroyLocks(ThreadPool *pool) {
    if (pthread_mutex_destroy(&(pool->lockMission)) != SYS_CALL_SUCCESS) {
        return SYS_CALL_FAIL;
    }
    if (pthread_mutex_destroy(&(pool->lockDestroy)) != SYS_CALL_SUCCESS) {
        return SYS_CALL_FAIL;
    }
    if (pthread_mutex_destroy(&(pool->lockQueue)) != SYS_CALL_SUCCESS) {
        return SYS_CALL_FAIL;
    }
    if (pthread_cond_destroy(&(pool->notify)) != SYS_CALL_SUCCESS) {
        return SYS_CALL_FAIL;
    }
    return SYS_CALL_SUCCESS;
}

//Run the missions using in the threads, missions are taken from the queue.
void *RunMission(void *args) {
    ThreadPool *threadPool = (ThreadPool *) args;
    while (threadPool->isRunning) {
        if (!threadPool->canAdd && osIsQueueEmpty(threadPool->queue)) {
            break;
        }
        //lock the queue
        if (pthread_mutex_lock(&(threadPool->lockQueue)) != SYS_CALL_SUCCESS) {
            OnFailure(threadPool);
        }
        //wait for the notifier
        if (osIsQueueEmpty(threadPool->queue) && threadPool->isRunning) {
            if (pthread_cond_wait(&(threadPool->notify), &(threadPool->lockQueue)) != SYS_CALL_SUCCESS) {
                OnFailure(threadPool);
            }
        }
        //unlock the queue
        if (pthread_mutex_unlock(&(threadPool->lockQueue)) != SYS_CALL_SUCCESS) {
            OnFailure(threadPool);
        }
        //lock the mission
        if (pthread_mutex_lock(&(threadPool->lockMission)) != SYS_CALL_SUCCESS) {
            OnFailure(threadPool);
        }
        //unlock if the queue is empty
        if ((osIsQueueEmpty(threadPool->queue))) {
            if (pthread_mutex_unlock(&(threadPool->lockMission)) != SYS_CALL_SUCCESS) {
                OnFailure(threadPool);
            }
            //if not run the mission and unlock
        } else {
            Mission *mission = osDequeue(threadPool->queue);
            if (!mission) {
                OnFailure(threadPool);
            }
            if (pthread_mutex_unlock(&(threadPool->lockMission)) != SYS_CALL_SUCCESS) {
                OnFailure(threadPool);
            }
            mission->computeFunc(mission->param);
            free(mission);
        }
    }
    return NULL;
}

//Create the Thread Pool.
ThreadPool *tpCreate(int numOfThreads) {
    //the thread pool,queue and threads are allocated
    ThreadPool *threadPool = (ThreadPool *) malloc(sizeof(ThreadPool));
    if (!threadPool) {
        OnFailure(threadPool);
    }
    threadPool->queue = osCreateQueue();
    if (!threadPool->queue) {
        OnFailure(threadPool);
    }
    threadPool->numOfThreads = numOfThreads;
    threadPool->threads = (pthread_t *) malloc(sizeof(pthread_t) * numOfThreads);
    if (!threadPool->threads) {
        OnFailure(threadPool);
    }
    //locks are initialized
    if (InitLocks(threadPool) == SYS_CALL_FAIL) {
        OnFailure(threadPool);
    }
    threadPool->isRunning = TRUE;
    threadPool->canAdd = TRUE;
    int i;
    //create the threads, run the missions from the queue.
    for (i = 0; i < numOfThreads; i++) {
        if (pthread_create(&(threadPool->threads[i]), NULL, RunMission, (void *) threadPool) != SYS_CALL_SUCCESS) {
            OnFailure(threadPool);
        }

    }
    return threadPool;
}

//Insert a mission to the Thread Pool, return value is if succeeded or failed.
int tpInsertTask(ThreadPool *threadPool, void (*computeFunc)(void *), void *param) {
    //check if correct input and the mission can be added
    if (!threadPool) {
        return INSERTION_FAIL;
    }
    if (!threadPool->canAdd || !threadPool->isRunning) {
        return INSERTION_FAIL;
    }

    Mission *mission = (Mission *) malloc(sizeof(Mission));
    if (!mission) {
        return INSERTION_FAIL;

    }
    mission->computeFunc = computeFunc;
    mission->param = param;
    //add mission to the queue
    osEnqueue(threadPool->queue, (void *) mission);
    //lock the queue
    if (pthread_mutex_lock(&(threadPool->lockQueue)) != SYS_CALL_SUCCESS) {
        return INSERTION_FAIL;

    }
    //notify the thread
    if (pthread_cond_signal(&(threadPool->notify)) != SYS_CALL_SUCCESS) {
        return INSERTION_FAIL;

    }
    //unlock the queue
    if (pthread_mutex_unlock(&(threadPool->lockQueue)) != SYS_CALL_SUCCESS) {
        return INSERTION_FAIL;
    }
    return INSERTION_SUCCESS;
}

//Destroy the Thread Pool.
void tpDestroy(ThreadPool *threadPool, int shouldWaitForTasks) {
    if (!threadPool) {
        return;
    }
    // lock
    if (pthread_mutex_lock(&(threadPool->lockDestroy)) != SYS_CALL_SUCCESS) {
        OnFailure(threadPool);
    }
    //check if missions can be added, if true stop adding.
    if (!threadPool->canAdd) {
        return;
    } else {
        threadPool->canAdd = FALSE;
    }
    // unlock
    if (pthread_mutex_unlock(&(threadPool->lockDestroy)) != SYS_CALL_SUCCESS) {
        OnFailure(threadPool);
    }
    //keep running if no tasks to wait for
    if (shouldWaitForTasks == DONT_WAIT) {
        threadPool->isRunning = TRUE;
    }
    //lock
    if (pthread_mutex_lock(&(threadPool->lockQueue)) != SYS_CALL_SUCCESS) {
        OnFailure(threadPool);
    }
    // notify the threads
    if ((pthread_cond_broadcast(&(threadPool->notify)) != SYS_CALL_SUCCESS)) {
        OnFailure(threadPool);
    }
    //unlock
    if (pthread_mutex_unlock(&(threadPool->lockQueue)) != SYS_CALL_SUCCESS) {
        OnFailure(threadPool);
    }
    //wait for the threads
    int j;
    for (j = 0; j < threadPool->numOfThreads; j++) {
        if (pthread_join(threadPool->threads[j], NULL) != SYS_CALL_SUCCESS) {
            OnFailure(threadPool);
        }

    }
    threadPool->isRunning = FALSE;
    //destroy the locks
    DestroyLocks(threadPool);
    //free the memory
    FreeMemory(threadPool);
}
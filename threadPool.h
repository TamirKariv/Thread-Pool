#ifndef __THREAD_POOL__
#define __THREAD_POOL__

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "osqueue.h"
#include <string.h>

#define SYS_CALL_SUCCESS 0
#define SYS_CALL_FAIL -1
#define INSERTION_SUCCESS 0
#define INSERTION_FAIL -1
#define SYS_CALL_ERROR "Error in system call\n"
#define DONT_WAIT 0
#define TRUE 1
#define FALSE 0


typedef struct thread_pool {
    int numOfThreads;
    int isRunning;
    int canAdd;
    pthread_t *threads;
    OSQueue *queue;
    pthread_mutex_t lockMission;
    pthread_mutex_t lockQueue;
    pthread_mutex_t lockDestroy;
    pthread_cond_t notify;
} ThreadPool;

typedef struct mission {
    void (*computeFunc)(void *param);

    void *param;
} Mission;

//Create the Thread Pool.
ThreadPool *tpCreate(int numOfThreads);
//Destroy the Thread Pool.
void tpDestroy(ThreadPool *threadPool, int shouldWaitForTasks);
//Insert a mission to the Thread Pool, return value is if succeeded or failed.
int tpInsertTask(ThreadPool *threadPool, void (*computeFunc)(void *), void *param);

#endif
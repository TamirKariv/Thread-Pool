cmake_minimum_required(VERSION 3.14)
project(untitled24 C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS -pthread)



add_executable(untitled24 main.c osqueue.c osqueue.h threadPool.c threadPool.h)
#define gcc

#ifndef WINDOWS
#define WINDOWS
#include <windows.h>
#endif

#ifndef STDINT
#define STDINT
#include <stdint.h>
#endif

#ifndef STDIO
#define STDIO
#include <stdio.h>
#endif

#ifndef STDLIB
#define STDLIB
#include <stdlib.h>
#endif

#ifndef STDATOMIC
#define STDATOMIC
#include <stdatomic.h>
#endif

#ifdef clang
#pragma clang optimize off
#endif

#ifdef gcc
#pragma GCC push_options
#pragma GCC optimize ("O0")
#endif

// TODO
// create different thread typed with different priority (sleep time)
// create lite_time_win32 or lite_system_win32.
// make thread() so that specific thread can be called


// 32 * number of physical cores
enum constant { THREAD_COUNT = 1024 };
atomic_uint_least32_t thread_count = 1;
DWORD thread_id[THREAD_COUNT];

atomic_uint_least8_t thread_work[THREAD_COUNT];
atomic_uint_least8_t thread_exit[THREAD_COUNT];
atomic_uint_least8_t thread_exited[THREAD_COUNT];
atomic_uint_least8_t thread_sync[THREAD_COUNT];
atomic_uint_least8_t thread_synced[THREAD_COUNT];

void (*thread_function[THREAD_COUNT])();

atomic_uint_least32_t thread_sleep = THREAD_COUNT * 100;
atomic_uint_least8_t thread_sync_done = 1;

/*
struct timespec thread_clock_start() {
    struct timespec start;
    clock_gettime(CLOCK_MONOTONIC, &start);
    return start;
}

void thread_clock_stop(struct timespec start) {
    struct timespec stop;
    clock_gettime(CLOCK_MONOTONIC, &stop);
    double result = stop.tv_nsec - start.tv_nsec;
    if (result < 0) {
        result = (result * -1) / 1000000;
    }
    else {
        result = result / 1000000;
    }
    printf("milliseconds: %f (thread)\n", result);
}

// add thread index
void thread_benchmark() { 
    struct timespec start = thread_clock_start();
    for (int i = 0; i < 10000000; i ++) {}
    thread_clock_stop(start);
}
void (*fp_thread_benchmark) = thread_benchmark;
*/



DWORD WINAPI thread_pool(LPVOID index) {

    int i = (intptr_t) index;
    while (1) {

        if (thread_exit[i] == 0) {
            if (thread_work[i] == 1) {
                (*thread_function[i])();                
                thread_function[i] = NULL;
                thread_work[i] = 0;
            }
            else {
                if (thread_sync[i] == 0) {
                    //usleep(thread_sleep);
                }
                else if (thread_synced[i] == 0) {
                    thread_synced[i] = 1;
                    //usleep(thread_sleep);
                }
                else if (thread_sync_done == 0) {
                    //usleep(thread_sleep);
                }
                else {
                    thread_sync[i] = 0;
                    thread_synced[i] = 0;
                }
            }
        }
        else {
            if (thread_work[i] == 1) {
                (*thread_function[i])();             
                thread_function[i] = NULL;
                thread_work[i] = 0;
                break;
            }
            else { 
                break;
            }
        } 
    }
    thread_exited[i] = 1;
    DWORD result;
    return result;
}



void thread_pool_start(int count) {

    thread_count = count;

    for (int i = 0; i < thread_count; i ++) {
        DWORD init_thread;
        thread_id[i] = init_thread;
    }
    for (int i = 0; i < thread_count; i ++) {
        thread_work[i] = 0;
    }
    for (int i = 0; i < thread_count; i ++) {
        thread_exit[i] = 0;
    }
    for (int i = 0; i < thread_count; i ++) {
        thread_exited[i] = 0;
    }
    for (int i = 0; i < thread_count; i ++) {
        thread_sync[i] = 0;
    }
    for (int i = 0; i < thread_count; i ++) {
        thread_synced[i] = 0;
    }
    for (int i = 0; i < thread_count; i ++) {
        thread_function[i] = NULL;
    }

    for (int i = 0; i < thread_count; i ++) {
        CreateThread(NULL, 0, thread_pool, (void *)(intptr_t) i, 0, &thread_id[i]);
    }
}



void thread_pool_sync() {

    thread_sync_done = 0;
    
    for (int i = 0; i < thread_count; i ++) {
        thread_sync[i] = 1;
    }

    for (int i = 0; i < thread_count; i ++) {
        int synced = 0;
        while (synced == 0) {
            if (thread_synced[i] == 1) {
                synced = 1;
            }
        }
    }
    thread_sync_done = 1;
}



void thread_pool_stop() {

    thread_sleep = thread_count * 100;

    for (int i = 0; i < thread_count; i ++) {
        thread_exit[i] = 1;
    }

    for (int i = 0; i < thread_count; i ++) {
        int exited = 0;
        while (exited == 0) {
            if (thread_exited[i] == 1) {
                exited = 1;
                thread_exit[i] = 0;
                thread_exited[i] = 0;
            }
        }
    }
     for (int i = 0; i < THREAD_COUNT; i ++) {
        DWORD re_init;
        thread_id[i] = re_init;
    }
    for (int i = 0; i < THREAD_COUNT; i ++) {
        thread_work[i] = 0;
    }
    for (int i = 0; i < THREAD_COUNT; i ++) {
        thread_exit[i] = 0;
    }
    for (int i = 0; i < THREAD_COUNT; i ++) {
        thread_exited[i] = 0;
    }
    for (int i = 0; i < THREAD_COUNT; i ++) {
        thread_sync[i] = 0;
    }
    for (int i = 0; i < THREAD_COUNT; i ++) {
        thread_synced[i] = 0;
    }
    for (int i = 0; i < THREAD_COUNT; i ++) {
        thread_function[i] = NULL;
    }
}


// use this to determine thread_sleep
uint_least32_t active_threads = 0;


void thread(void (*func)()) {

    int done = 0;
    while (done == 0) {
        for (int i = 0; i < thread_count; i ++) {
            if (thread_work[i] == 0) { 
                done = 1;
                thread_function[i] = func;
                thread_work[i] = 1; 
                break; 
            }
        }
    }
}

#ifdef clang
#pragma clang optimize on
#endif

#ifdef gcc
#pragma GCC pop_options
#endif



int main() {
    return 0;
}

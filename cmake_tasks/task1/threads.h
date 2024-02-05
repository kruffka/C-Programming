#ifndef __THREADS_H__
#define __THREADS_H__

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define N 10

typedef struct proc {
    pthread_t thread_id;
    int priority;
    int flag;
} proc_t;

extern proc_t proc[N];
extern FILE *file;

void *readThread(proc_t *thr);
void *writeThread(proc_t *thr);

#endif
// При сбокре не забываем слинковать с pthread
// gcc thread1.c -o thread1 -lpthread
//

#include <stdio.h>
#include <unistd.h> // sleep
#include <pthread.h>

#define NOF_THREADS 5

void *routine(void *_) {
    pthread_t tid = pthread_self();
    printf("hello from slave thread %ld\n", tid);
    sleep(2);
    return NULL;
}

int main(void) {

    pthread_t tids[NOF_THREADS];
    for (int i = 0; i < NOF_THREADS; i++) {
        pthread_create(&tids[i], NULL, routine, NULL);
    }

    printf("hello from main thread %ld\n", pthread_self());

    for (int i = 0; i < NOF_THREADS; i++) {
        pthread_join(tids[i], NULL);
    }
    return 0;
}
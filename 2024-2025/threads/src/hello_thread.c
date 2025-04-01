// При сбокре не забываем слинковать с pthread
// gcc thread1.c -o thread1 -lpthread
//

#include <stdio.h>
#include <unistd.h> // sleep
#include <pthread.h>

#define N 10

void *routine(void *_) {
    for (int i = 0; i < N; i++) {
        printf("thread: i=%d\n", i);
        sleep(2);
    }
    return NULL;
}

int main(void) {

    pthread_t tid;
    pthread_create(&tid, NULL, routine, NULL);
    for (int i = 0; i < N; i++) {
        printf("main process: i=%d\n", i);
        sleep(1);
    }

    pthread_join(tid, NULL); // Можно закомментировать эту строку и все sleep, а затем позапускать позапускать еще

    return 0;
}
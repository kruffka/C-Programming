// При сбокре не забываем слинковать с pthread
// gcc thread1.c -o thread1 -lpthread
//

#include <stdio.h>
#include <unistd.h> // sleep
#include <pthread.h>

#define N 100000000

int i = 0;

void *count_thread(void *_) {

    for (int k = 0; k < N; k++) {
        i++;
    }
    return NULL;
}

int main(void) {

    pthread_t tid;
    pthread_create(&tid, NULL, count_thread, NULL);

    for (int k = 0; k < N; k++) {
        i++;
    }

    pthread_join(tid, NULL); // Можно закомментировать эту строку и все sleep, а затем позапускать позапускать еще

    printf("result is %d\n", i);

    return 0;
}
// При сбокре не забываем слинковать с pthread
// gcc thread1.c -o thread1 -lpthread
//

#include <stdio.h>
#include <unistd.h> // sleep
#include <pthread.h>
#include <stdlib.h>

#define N 5

void *thread(void *argP) {
    int *var = (int *)argP;
    printf("thread got arg = %d\n", *var);

    return NULL;
}

int main(void) {

    pthread_t tid[N];

    for (int i = 0; i < N; i++) {
        pthread_create(&tid[i], NULL, thread, (void *)&i);
    }

    for (int i = 0; i < N; i++) {
        pthread_join(tid[i], NULL);
    }

    return 0;
}
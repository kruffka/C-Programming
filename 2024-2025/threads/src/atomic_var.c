#include <stdio.h>
#include <pthread.h>
#include <stdint.h>

#define BIG 100000000

_Atomic uint32_t atomic_counter = 0; // попробуй убрать _Atomic

void count() {
    for (int i = 0; i < BIG; i++) {
        atomic_counter++;
        // atomic_counter = atomic_counter + 1; // если сделать так, то уже не работает :(
    }
}

void *thread_func(void *arg) {

    count();

    return NULL;
}

int main(void) {

    pthread_t tid;
    pthread_create(&tid, NULL, thread_func, NULL);

    count();

    pthread_join(tid, NULL);

    printf("counter %d\n", atomic_counter);

    return 0;
}
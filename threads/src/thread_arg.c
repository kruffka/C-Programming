// При сбокре не забываем слинковать с pthread
// gcc thread1.c -o thread1 -lpthread
//

#include <stdio.h>
#include <unistd.h> // sleep
#include <pthread.h>
#include <stdlib.h>

void *thread(void *argP) {
    int *var = (int *)argP;
    printf("thread got arg = %d\n", *var);

    *var = 123;

    printf("thread change arg = %d\n", *var);

    int *ret = malloc(sizeof(int));
    *ret = 555;

    printf("thread return var = %d\n", *ret);

    return ret;
}

int main(void) {

    pthread_t tid;

    // передадим в поток, типы данных могут быть любые т.к. приводятся к (void *)
    // в данном примере пусть будет int
    int a = 5;
    int *b; // заберем из потока

    printf("main a = %d\n", a);
    
    pthread_create(&tid, NULL, thread, (void *)&a);
    pthread_join(tid, (void *)&b);

    printf("main a = %d, b = %d\n", a, *b);

    return 0;
}
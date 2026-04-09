#include <stdio.h>
#include <pthread.h>
#include <stdint.h> // uint8_t
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>


// ==========================================================================
// ======================     simple FIFO example     =======================
// ==========================================================================

typedef struct elem {
    char *msg;
} elem_t;

typedef struct fifo {

    pthread_mutex_t lock;
    pthread_cond_t cond;
    int length;
    int start;

    int fifo_max_queue_size;
    elem_t *elems; // ring buffer

    bool is_running;

} fifo_t;

fifo_t *fifo_init(int max_fifo_size) {

    fifo_t *fifo = malloc(sizeof(fifo_t));
    if (fifo == NULL) {
        return NULL;
    }

    if (pthread_mutex_init(&fifo->lock, NULL) != 0) {
        free(fifo);
        return NULL;
    }
    if (pthread_cond_init(&fifo->cond, NULL) != 0) {
        free(fifo);
        return NULL;
    }

    fifo->elems = malloc(max_fifo_size * sizeof(elem_t));
    if (fifo->elems == NULL) {
       free(fifo);
       return NULL;
    }
    fifo->fifo_max_queue_size = max_fifo_size;

    fifo->length = 0;
    fifo->start = 0;

    return fifo;
}

void fifo_deinit(fifo_t *fifo) {
    if (fifo) free(fifo->elems);
    free(fifo);
}

void *thread_dequeue(void *argP) {

    fifo_t *fifo = (fifo_t *)argP;
    if (fifo == NULL) return NULL;

    char *msg = NULL;
    int idx = 0;
    while (fifo->is_running) {

        // Ждем сообщения и забираем их из очереди
        if (pthread_mutex_lock(&fifo->lock) != 0) abort();
        while (fifo->length == 0 && fifo->is_running) { // очередь пуста
            printf("thread queue is empty: wait\n");
            if (pthread_cond_wait(&fifo->cond, &fifo->lock) != 0) abort(); // ждем
        }

        msg = fifo->elems[fifo->start].msg;
        fifo->elems[fifo->start].msg = NULL;

        if (pthread_mutex_unlock(&fifo->lock) != 0) abort();

        
        // Здесь поток делает что-то трудоемкое
        idx++;        
        if (msg) {
            printf("thread <= main: recv %s, i %d, idx %d, start %d, len %d/%d\n", msg, idx, fifo->start, fifo->start, fifo->length, fifo->fifo_max_queue_size);
            free(msg);
        }


        // Освобождаем место в очереди
        if (pthread_mutex_lock(&fifo->lock) != 0) abort();

        fifo->start = (fifo->start + 1) % fifo->fifo_max_queue_size;
        fifo->length--;

        if (pthread_cond_signal(&fifo->cond) != 0) abort();
        if (pthread_mutex_unlock(&fifo->lock) != 0) abort();
    }

    return NULL;
}

bool isEmpty(fifo_t *fifo) {
    return fifo->length == 0;
}

int main(void) {

    const int fifo_max_queue_size = 5;
    fifo_t *fifo = fifo_init(fifo_max_queue_size);

    if (fifo == NULL) {
        return 1;
    }

    fifo->is_running = true;
    pthread_t thread;
    pthread_create(&thread, NULL, thread_dequeue, (void *)fifo);

    int idx;
    for (int i = 0; i < 50; i++) {
        char *msg = malloc(8);
        snprintf(msg, 8, "msg%u", i);

        if (pthread_mutex_lock(&fifo->lock) != 0) abort();
        
        while (fifo->length >= fifo->fifo_max_queue_size) { // очередь переполнена
            printf("main => thread queue is full: wait\n");
            if (pthread_cond_wait(&fifo->cond, &fifo->lock) != 0) abort(); // ждем
        }
    
        idx = (fifo->start + fifo->length) % fifo_max_queue_size;
        printf("main => thread: send %s, i %d, idx %d, start %d, len %d/%d\n", msg, i, idx, fifo->start, fifo->length, fifo->fifo_max_queue_size);

        fifo->elems[idx].msg = msg;
        fifo->length++;

        if (pthread_cond_signal(&fifo->cond) != 0) abort();
        if (pthread_mutex_unlock(&fifo->lock) != 0) abort();

    }

    while(!isEmpty(fifo)) { // Дождемся пока вся очередь обработается
        usleep(1000);
    }

    // Завершим thread
    if (pthread_mutex_lock(&fifo->lock) != 0) abort();
    fifo->is_running = false;
    if (pthread_cond_signal(&fifo->cond) != 0) abort();
    if (pthread_mutex_unlock(&fifo->lock) != 0) abort();
    
    // дождемся завершения thread
    pthread_join(thread, NULL);

    // память
    fifo_deinit(fifo);

    return 0;
}
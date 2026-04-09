#include <stdio.h>
#include <pthread.h>
#include <stdint.h> // uint8_t
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

// ===================================================================
// ====================== simple tpool example =======================
// ===================================================================

typedef void *(*task_func)(void *);

typedef void *task_arg;

typedef struct task {
    task_func func;
    task_arg arg;
} task_t;

#define MAX_TASK_QUEUE_SIZE (10)

typedef struct tpool {
#define RING_BUF_SIZE (MAX_TASK_QUEUE_SIZE * 2)
    task_t tasks[RING_BUF_SIZE];
    
    pthread_mutex_t lock;
    pthread_cond_t cond;
    int length;

    uint8_t nof_threads;
    
    struct thread_info {
        uint8_t id; // friendly id
        pthread_t tid; // thread id
    } *threads;

} tpool_t;

// создадим и инициализируем глобально для простоты
tpool_t tpool_g = {
    .tasks = {0},
    .lock = PTHREAD_MUTEX_INITIALIZER,
    .cond = PTHREAD_COND_INITIALIZER,
    .length = 0,
    .threads = NULL,
    .nof_threads = 0
};

void enqueue_task(task_func func, task_arg arg) {
    int idx;
    if (pthread_mutex_lock(&tpool_g.lock) != 0) abort();
    while (tpool_g.length >= MAX_TASK_QUEUE_SIZE) { // очередь переполнена
        if (pthread_cond_wait(&tpool_g.cond, &tpool_g.lock) != 0) abort(); // ждем
    }

    tpool_g.tasks[tpool_g.length].func = func;
    tpool_g.tasks[tpool_g.length].arg = arg;
    tpool_g.length = (tpool_g.length + 1) % RING_BUF_SIZE;

    if (pthread_cond_signal(&tpool_g.cond) != 0) abort();
    if (pthread_mutex_unlock(&tpool_g.lock) != 0) abort();
}

void dequeue_task(task_t *task) {
    if (pthread_mutex_lock(&tpool_g.lock) != 0) abort();
    while (tpool_g.length <= 0) { // очередь пуста
        if (pthread_cond_wait(&tpool_g.cond, &tpool_g.lock) != 0) abort(); // ждем
    }
    tpool_g.length--;
    task->arg = tpool_g.tasks[tpool_g.length].arg;
    task->func = tpool_g.tasks[tpool_g.length].func;

    if (pthread_cond_signal(&tpool_g.cond) != 0) abort();
    if (pthread_mutex_unlock(&tpool_g.lock) != 0) abort();

}


static void *worker(void *argP) {
    
    struct thread_info *data = (struct thread_info *)argP;
    if (data == NULL) {
        return NULL;
    }
    char thread_name[16] = "";
    snprintf(thread_name, sizeof(thread_name), "thread%u", data->id);
    pthread_setname_np(thread_name); // в htop всем будет видно имя потока
    printf("hello, my name is.. %s\n", thread_name);

    task_t task;
    while (1) {
        // Спим пока не прилетит таска
        int idx;
        printf("[%s]: wait for work\n", thread_name);
        dequeue_task(&task);

        printf("[%s]: got work to do\n", thread_name);
        if (task.func) {
            task.func(task.arg);
        }
        printf("[%s]: work done\n", thread_name);

    }

    return NULL;
}

int tpool_init(tpool_t *tpool, uint8_t nof_threads) {

    if (tpool == NULL) {
        return -1;
    }

    tpool->nof_threads = nof_threads;
    tpool->threads = (struct thread_info *)calloc(1, nof_threads * sizeof(struct thread_info));
    if (tpool->threads == NULL) {
        return -1;
    }

    for (uint8_t t = 0; t < tpool->nof_threads; t++) {
        tpool->threads[t].id = t;
        pthread_create(&tpool->threads[t].tid, NULL, worker, &tpool->threads[t]);
    }

    return 0;
}

void tpool_deinit(tpool_t *tpool) {
    if (!tpool) {
        return;
    }
    free(tpool->threads);
    tpool->nof_threads = 0;
}

void tpool_stop(tpool_t *tpool) {

    // ждем пока все потоки закончат работу
    sleep(1);

    printf("main: stop tpool\n");
    for (int t = 0; t < tpool->nof_threads; t++) {
        pthread_cancel(tpool->threads[t].tid);
    }

}

// ===================================================================
// ===================================================================
// ===================================================================

void *heavy_task(void *argP) {

    printf("Executing task %d\n", *(int *)argP);
    usleep(100000);
}

int main(int argc, char *argv[]) {

    int nof_threads = argc > 1 ? atoi(argv[1]) : 4;

    tpool_t *t = &tpool_g;
    int ret = tpool_init(t, nof_threads);
    if (ret < 0) {
        return -1;
    }

    for (int i = 0; i < 42; i++) {
        int *arg = malloc(sizeof(int));
        *arg = i;
        printf("main => tpool: send task %d\n", i);
        enqueue_task(heavy_task, arg);
    }

    tpool_stop(t);
    tpool_deinit(t);

    return 0;
}
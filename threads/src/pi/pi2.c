// При компиляции слинковать с математикой и pthread: -lm -lphtread

#include <stdio.h>
#include <math.h>
#include <pthread.h>
#include <stdlib.h>

struct data {
    pthread_t tid; // id потока
    int thread_num; // Номер потока
    int start; // начальная точка
    int end; // конечная точка
};

double s = 0.0;
const int n = 100000000;
const double a = -5.;
const double b = 5.0;
const double h = (b - a) / n;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; // или можно через pthread_mutex_init()

double f(double x) {
    return exp(-x * x);
}

void *pi(void *argP) {
    struct data *tdata = (struct data *)argP;
    printf("thread %d start for [%d, %d)\n", tdata->thread_num, tdata->start, tdata->end);

    double local = 0;
    for (int i = tdata->start; i < tdata->end; i++) {
        local += f(a + h * (i + 0.5));
    }

    local *= h;

    pthread_mutex_lock(&mutex);
    s += local;
    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main(int argc, char *argv[]) {

    int nof_threads;
    if (argc > 1) {
        nof_threads = atoi(argv[1]);
    } else {
        nof_threads = 2; // Один основной и один pthread
    }

    printf("Start integration for %d points with %d threads [%lf, %lf]\n", n, nof_threads, a, b);

    struct data *tdata = malloc(nof_threads * sizeof(struct data));
    if (tdata == NULL) {
        printf("Error malloc data\n");
        exit(1);
    }
    
    int points_per_thread = n / nof_threads;

    for (int i = 1; i < nof_threads; i++) { // с 1, т.к. 0 будет main() поток
        tdata[i].thread_num = i;
        tdata[i].start = i * points_per_thread;
        tdata[i].end = tdata[i].start + points_per_thread;
        pthread_create(&tdata[i].tid, NULL, pi, &tdata[i]);
    }

    tdata[0].thread_num = 0; // главный поток тоже пусть учавствует
    tdata[0].start = 0; // i * points_per_thread
    tdata[0].end = points_per_thread; // tdata[0].start + points_per_thread   
    pi(&tdata[0]);

    for (int i = 0; i < nof_threads; i++) {
        pthread_join(tdata[i].tid, NULL);
    }

    s = s*s; // т.к. e^(-x^2) дает нам корень Пи
    printf("my   pi = %.12lf\n", s);
    printf("math pi = %.12lf\n", M_PI);

    free(tdata);
    return 0;
}
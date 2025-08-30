#include "threads.h"
#include <math.h>

// global
proc_t proc[N];
FILE *file;

void main() {

    srand(time(NULL));

    file = fopen("text.txt", "w+r");
    if(file == NULL) {
        printf("file == NULL\n");
        exit(5);
    }
    
    proc[0].priority = 99;

    pthread_create(&proc[0].thread_id, NULL, writeThread, &proc[0]);
    for (int i = 1; i < N; i++) {
        proc[i].priority = i;
        pthread_create(&proc[i].thread_id, NULL, readThread, &proc[i]);
    }
    printf("123\n");

    for (int i = 0; i < N; i++) {
        pthread_join(proc[i].thread_id, NULL);

    }

    fclose(file);
    exit(0);
    
}
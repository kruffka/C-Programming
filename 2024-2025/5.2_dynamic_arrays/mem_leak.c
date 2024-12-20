#include <stdio.h>
#include <stdlib.h> // для malloc(), calloc(), realloc() и free()

#define N 5

// Утечка памяти в примере заключается в том, что мы выделяя память 2 раза, но адрес на эту память записали в один и тот же указатель
// т.е. перезатираем адрес на 1 выделенную память и теряем этот адрес навсегда. Память выделенную первый раз мы сможем освободить лишь завершением программы (Система чистит память при завершении программы)

int main(void) {

    int *arr = NULL;
    
    arr = (int *)malloc(N * sizeof(int)); // Выделили память под N int'ов и адрес начала этой памяти поместили в arr

    // Снова выделяем 3 int'а, и записываем новый адрес на выделенную память
    arr = (int *)malloc(3 * sizeof(int)); // Здесь утечка

    // освобождаем память
    free(arr);
    arr = NULL;

    return 0;
}
#include <stdio.h>
#include <string.h> // для memset()

// Функция как параметр - callback
void filter(int size_in, const int in[], int size_out, int out[], int (*condition_func)(int)) {

    memset(out, 0, size_out*sizeof(out[0])); // Функция заполнения нулями, начиная с адреса out заполняем 0 sizeof(out) байт

    int j = 0;
    for (int i = 0; i < size_in; i++) {
        if (condition_func(in[i])) { // вызываем функцию, которую передали
            out[j++] = in[i];
        }
    }
}

int is_even(int num) {
    if (num % 2 == 0) {
        return 1;
    } else {
        return 0;
    }
}

int is_odd(int num) {
    return num % 2 == 0 ? 0 : 1;
}

#define SIZE 5

int main(void) {

    int A[] = {1, 2, 3, 4, 5};
    int B[SIZE];

    printf("Filter even numbers\n");
    filter(sizeof(A) / sizeof(A[0]), A, SIZE, B, is_even); // передаем указатель на функцию в функцию как аргумент

    for (int i = 0; i < SIZE; i++) {
        printf("A[%d] = %d, B[%d] = %d\n", i, A[i], i, B[i]);
    }

    printf("\nFilter odd numbers\n");
    filter(SIZE, A, SIZE, B, is_odd);

    for (int i = 0; i < SIZE; i++) {
        printf("A[%d] = %d, B[%d] = %d\n", i, A[i], i, B[i]);
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#define N 3

void print_array(char **arr) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }
}

int main(void) {

    // Сначала массив из N указателей - будущие строки матрицы
    char **arr = malloc(N * sizeof(*arr));
    if (arr == NULL) {
        printf("Error malloc!\n");
        return 1;
    }

    for (int i = 0; i < N; i++) {
        arr[i] = malloc(N * sizeof(**arr)); // каждая строка - N символов
        if (arr[i] == NULL) {
            printf("Error malloc!\n");
            return 1;
        }
        for (int j = 0; j < N; j++) {
            arr[i][j] = 'A' + i; // 'A', 'B', 'C'
        }
    }

    print_array(arr);
    printf("\n");

    **arr = 'X';                // или arr[0][0] = 'X';
    *(*(arr + 1) + 2) = 'Y';    // или arr[1][2] = 'Y';

    print_array(arr);

    // освобождаем в порядке, обратном выделению
    for (int i = 0; i < N; i++) {
        free(arr[i]);
        arr[i] = NULL;
    }
    free(arr);
    arr = NULL;

    return 0;
}

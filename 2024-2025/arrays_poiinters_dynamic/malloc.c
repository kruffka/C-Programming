#include <stdio.h>
#include <stdlib.h> // для malloc(), calloc(), realloc() и free()

#define N 100

int main(void) {

    // выделяем память в куче (heap) под N * sizeof(int) байт, т.е. под N int элементов, статически выглядело бы как: int arr[N];
    int *arr = (int *)malloc(N * sizeof(int)); // malloc возвращает (void *), поэтому преобразуем тип к int *, т.к. хотим массив из int

    // Если память выделить не удалось, то вернется NULL. Такое легко получить если попробовать выделить очень много памяти
    if (arr == NULL) {
        printf("Error in malloc!\n");
        return -1;
    }

    // работаем как с обычным массивом
    arr[0] = 123; // или *arr = 123

    // выводим как обычный массив
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]); // выводим элементы, есть шанс увидеть мусор вместо 0
    }
    printf("\n");

    // Освобождение памяти, массив нам надоел и больше не нужен
    free(arr);
    arr = NULL; // Для избежания ошибок и быстрого поиска ошибок с указателем при переиспользовании переменной arr


    // Выделение памяти под N-мерные массивы на примере двумерного (матрица)
    float **arr2 = (float **)malloc(N * sizeof(float *)); // Выделим память под N указателей на float
    if (arr2 == NULL) {
        printf("Error in malloc arr2!\n");
        return -1;
    }

    for (int i = 0; i < N; i++) {
        arr2[i] = (float *)malloc(N * sizeof(float)); // Выделим память под N элементов типа float и записываем в наш массив указателей
        if (arr2[i] == NULL) {
            printf("Error in malloc arr2!\n");
            return -1;
        }
    }

    // Пользуемся памятью
    arr2[0][0] = 123.55;

    /* 
    int arr[3][3]; 
    1 2 3
    4 5 6
    7 8 9
        int** -----------> int* -> [1, 2, 3]
                           int* -> [4, 5, 6]
        +2*sizeof(int**)-> int* -> [7, 8, 9]
    */

    // Освобождаем в обратном порядке
    for (int i = 0; i < N; i++) {
        free(arr2[i]);
        arr2[i] = NULL;
    }

    free(arr2);
    arr2 = NULL;

    

    return 0;
}
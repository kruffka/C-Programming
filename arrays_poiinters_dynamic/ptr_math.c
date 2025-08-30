#include <stdio.h>

int main(void) {

    int a = 5;
    int *ptr = NULL; // Указатель на int
   
    ptr = &a;
    printf("ptr = %p\n", ptr); // Значение переменной ptr
    printf("*ptr = %d\n", *ptr); // Разыменовываем переменную ptr: прыгаем по адресу из ptr и вытаскиваем значение a
    printf("&ptr = %p\n", &ptr); // Адрес переменной ptr

    printf("a = %d\n", a); // *ptr и a это одни и те же данные
    *ptr = *ptr + 5;
    printf("a = %d\n", a); // *ptr и a это одни и те же данные


    printf("ptr = %p\n", ptr); // Значение переменной ptr
    ptr = ptr + 1; // прибавиться не 1 байт, а 1*sizeof(int) байт, т.е. 4 байта
    printf("ptr = %p\n", ptr); // Значение переменной ptr


    // Примеры связи указателей и массивов
    int arr[] = {1, 2, 3, 4, 5};
    unsigned int size = sizeof(arr) / sizeof(arr[0]);
    // Выведем массив привычным способом
    for (int i = 0; i < size; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    // Теперь тоже самое, но с использованием указателя
    // название массива - есть адрес на его нулевой элемент, т.е. arr == &arr[0]
    for (int i = 0; i < size; i++) {
        printf("*(arr + %d) = %d\n", i, *(arr + i)); // при добавлении i добавляется i * sizeof(int) байт к адресу, т.к. arr массив из int
    }

    // С N-мерными массивами
    int arr2[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}; // двумерный массив (матрица)
    unsigned int size2 = sizeof(arr2) / sizeof(arr2[0]);
    // Выведем массив привычным способом
    for (int n = 0; n < size2; n++) {
        for (int m = 0; m < size2; m++) {
            printf("arr[%d][%d] = %d\n", n, m, arr2[n][m]);
        }
        printf("\n");
    }
    
    // Теперь тоже самое, но с использованием указателя
    for (int n = 0; n < size2; n++) { // номер строки
        for (int m = 0; m < size2; m++) { // номер столбца
            printf("*(*(arr2 + %d) + %d) = %d\n", n, m, *(*(arr2 + n) + m)); // Прибавляем номер строки, затем номер столбца
        }
        printf("\n");
    }


    // Пример с выводом байт числа

    int test = 0x00C0FFEE; // число в hex, которое в десятичной 12648430
    char *p = &test; // char всегда имеет размер один байт

    printf("first byte of a = 0x%hhX\n", *p); // 0xEE
    p++; // тоже самое что и p = p + 1
    printf("second byte of a = 0x%hhX\n", *p); // 0xFF
    p++;
    // ..


    return 0;
}
#include <stdio.h>
#include <stdlib.h>

// Демо для утилиты nm: смотрим, в какие секции памяти попадают переменные

int a;            // BSS: глобальная без инициализации -> 0
int b = 7;        // Data: глобальная с инициализацией
static int c = 0; // BSS: статическая, инициализирована нулём

int main(void) {

    double d = 1.5;         // стек
    short e = 1;            // стек
    void *ptr = malloc(20); // куча

    printf("a = %d, b = %d, c = %d, d = %lf, e = %hd, ptr = %p\n", a, b, c, d, e, (void *)ptr);

    free(ptr);
    ptr = NULL;

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10
#define M 5

int main() {

    char *str = (char *)malloc(N * sizeof(char)); // выделяем массив размером N байт
    if (str == NULL) return -1;

    strncpy(str, "hello", N);
    str[N - 1] = '\0'; // конец строки

    printf("str = %s\n", str);

    str = realloc(str, M * sizeof(char)); // уменьшим массив до M байт
    if (str == NULL) return -1;

    strncpy(str, "bye", M);
    str[M - 1] = '\0';

    printf("str = %s\n", str);

    free(str);
    str = NULL; 

    return 0;
}
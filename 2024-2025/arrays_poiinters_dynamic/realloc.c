#include <stdio.h>
#include <stdlib.h> // для malloc(), calloc(), realloc() и free()

#define N 10
#define M (N - 5) // M будет равен N - 5

int main(void) {

    // выделяем память
    char *str = (char *)calloc(1, N * sizeof(char));

    // Если память выделить не удалось, то вернется NULL. Такое легко получить если попробовать выделить очень много памяти
    if (str == NULL) {
        printf("Error in calloc!\n");
        return -1;
    }

    // работаем как с обычным массивом
    for (int i = 0 ; i < N; i++) {
        str[i] = 'A' + i; // или *(str + i) = 'A' + i
    }
    str[N - 1] = '\0'; // конец строки

    // Выводим как строку
    printf("my str is: %s\n", str);

    str = realloc(str, M * sizeof(char)); // изменяем размер массива
    str[M - 1] = '\0';

    // Выводим как строку
    printf("new str is: %s\n", str);

    // Освобождение памяти, массив нам надоел и больше не нужен
    free(str);
    str = NULL; // Для избежания ошибок и быстрого поиска ошибок с указателем при переиспользовании переменной arr

    return 0;
}
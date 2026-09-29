#include <stdio.h>
#include <stdlib.h> // rand(), srand()
#include <time.h>   // time()

#define N 10

// Случайное число в диапазоне [min..max]
int rand_range(int min, int max) {
    return min + rand() % (max - min + 1);
}

int main(void) {

    // Без srand() последовательность всегда одинаковая - удобно для отладки
    printf("rand() = %d\n", rand()); // всегда 1804289383

    // seed задаём один раз за программу, иначе числа повторятся
    srand(time(NULL));
    printf("Unix timestamp = %ld\n", time(NULL));

    // Тестовые данные вместо реальных замеров
    printf("Температура на улице: %d C\n", rand_range(-30, 35));
    printf("Бросок кубика: %d\n", rand_range(1, 6));

    // Заполняем массив показаний датчиков за день
    int sensor[N];
    for (int i = 0; i < N; i++) {
        sensor[i] = rand_range(-30, 35);
    }

    printf("Показания датчика: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", sensor[i]);
    }
    printf("\n");

    return 0;
}

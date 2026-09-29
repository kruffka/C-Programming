#include <stdio.h>

#define DIM 4 // у настоящих эмбеддингов 768-4096 чисел

// Скалярное произведение - "похожесть" двух векторов
int dot(int n, const int a[n], const int b[n]) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i] * b[i];
    }
    return sum;
}

int main(void) {

    // Три "слова"... четыре :)
    char words[4][16] = {"кот", "кошка", "трактор", "пёс"};

    // Игрушечные эмбеддинги: числа = смысловые признаки.
    // Признаки 1-2 - "мягкое и мурчащее", 3-4 - "железное и большое".
    int vectors[4][DIM] = {
        {9, 7, 0, 0}, // кот
        {8, 9, 0, 0}, // кошка
        {0, 1, 1, 9}, // трактор
        {8, 6, 0, 1}  // пёс
    };

    int query[DIM] = {9, 9, 0, 0}; // вектор слова "котёнок"

    int best = 0;
    for (int i = 0; i < 4; i++) {
        printf("%s: похожесть = %d\n", words[i], dot(DIM, vectors[i], query));
        if (dot(DIM, vectors[i], query) > dot(DIM, vectors[best], query)) {
            best = i;
        }
    }

    printf("\nКто ближе всего к \"котёнку\": %s\n", words[best]);

    // Замечание: у настоящих моделей векторы вещественные,
    // а похожесть считают косинусной (нужен sqrt -> -lm)

    return 0;
}

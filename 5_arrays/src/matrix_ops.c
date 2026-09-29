#include <stdio.h>

#define SHOPS 3
#define DAYS  4

void print_matrix(int rows, int cols, const int m[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%6d", m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int sum_matrix(int rows, int cols, const int m[rows][cols]) {
    int sum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum += m[i][j];
        }
    }
    return sum;
}

int main(void) {

    // Выручка магазинов сети по дням недели, тыс. руб.
    int sales[SHOPS][DAYS] = {
        {120, 150, 130, 170},
        {90,  110, 95,  140},
        {200, 180, 210, 230}
    };

    printf("Выручка (магазины x дни), тыс. руб.:\n");
    print_matrix(SHOPS, DAYS, sales);
    printf("Выручка сети за неделю: %d тыс. руб.\n\n", sum_matrix(SHOPS, DAYS, sales));

    // Итог по каждому магазину (строка)
    for (int i = 0; i < SHOPS; i++) {
        int shop_total = 0;
        for (int j = 0; j < DAYS; j++) {
            shop_total += sales[i][j];
        }
        printf("магазин %d за неделю: %d тыс. руб.\n", i + 1, shop_total);
    }

    // Итог по каждому дню (столбец)
    for (int j = 0; j < DAYS; j++) {
        int day_total = 0;
        for (int i = 0; i < SHOPS; i++) {
            day_total += sales[i][j];
        }
        printf("день %d по всей сети: %d тыс. руб.\n", j + 1, day_total);
    }

    // Транспонирование: было "магазины x дни" - стало "дни x магазины"
    int by_day[DAYS][SHOPS];
    for (int i = 0; i < SHOPS; i++) {
        for (int j = 0; j < DAYS; j++) {
            by_day[j][i] = sales[i][j];
        }
    }
    printf("\nОтчёт по дням (дни x магазины):\n");
    print_matrix(DAYS, SHOPS, by_day);

    return 0;
}

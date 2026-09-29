#include <stdio.h>

#define ORDERS 8

// Индекс первого заказа с этим товаром или -1, если не заказывали
int first_order(int n, const int orders[n], int item) {
    for (int i = 0; i < n; i++) {
        if (orders[i] == item) {
            return i;
        }
    }
    return -1;
}

// Сколько раз товар встретился в заказах
int count_orders(int n, const int orders[n], int item) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (orders[i] == item) {
            count++;
        }
    }
    return count;
}

int main(void) {

    // Штрихкоды товаров в заказах за день
    int orders[ORDERS] = {4001, 5002, 7003, 4001, 9004, 1005, 4001, 6006};
    int item = 4001; // ходовой товар

    int index = first_order(ORDERS, orders, item);
    if (index == -1) {
        printf("Товар %d сегодня не заказывали\n", item);
    } else {
        printf("Первый заказ с товаром %d - в позиции %d\n", item, index);
    }

    printf("Всего заказов с этим товаром: %d\n", count_orders(ORDERS, orders, item));

    return 0;
}

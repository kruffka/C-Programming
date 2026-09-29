#include <stdio.h>

#define BASKET 6

// Самый дорогой товар в корзине
int most_expensive(int n, const int prices[n]) {
    int max = prices[0]; // именно с первого товара, а не с нуля
    for (int i = 1; i < n; i++) {
        if (prices[i] > max) {
            max = prices[i];
        }
    }
    return max;
}

int main(void) {

    int basket[BASKET] = {199, 89, 1290, 450, 79, 640}; // цены, руб.
    int n = (int)(sizeof(basket) / sizeof(basket[0]));

    printf("Корзина: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", basket[i]);
    }
    printf("руб.\n");

    printf("Самая дорогая позиция: %d руб.\n", most_expensive(n, basket));

    return 0;
}

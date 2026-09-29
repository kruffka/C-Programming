#include <stdio.h>

#define N 6

void bubble_sort(int size, int arr[size]) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) { // текущий больше следующего -> swap
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

void print_prices(int n, const int prices[n]) {
    for (int i = 0; i < n; i++) {
        printf("%d ", prices[i]);
    }
    printf("руб.\n");
}

int main(void) {

    // Каталог интернет-магазина: цены товаров
    int prices[N] = {1290, 199, 450, 89, 640, 79};

    printf("Цены как попало:   ");
    print_prices(N, prices);

    bubble_sort(N, prices); // по возрастанию цены

    printf("По возрастанию:    ");
    print_prices(N, prices);

    return 0;
}

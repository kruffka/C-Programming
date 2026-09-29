#include <stdio.h>

#define DAYS 10

void print_arr(int n, const int arr[n]) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Максимальная сумма k подряд идущих дней (скользящее окно)
int best_window(int n, const int revenue[n], int k) {
    int sum = 0;
    for (int i = 0; i < k; i++) {
        sum += revenue[i];
    }
    int best = sum;
    for (int i = k; i < n; i++) {
        sum += revenue[i] - revenue[i - k]; // пришёл новый день, ушёл старый
        if (sum > best) {
            best = sum;
        }
    }
    return best;
}

// Префиксные суммы: prefix[i] - выручка за первые i дней
void build_prefix(int n, const int revenue[n], int prefix[n + 1]) {
    prefix[0] = 0;
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + revenue[i];
    }
}

// Бинарный поиск в ОТСОРТИРОВАННОМ прайсе: индекс или -1
int binary_search(int n, const int prices[n], int price) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (prices[mid] == price) {
            return mid;
        }
        if (prices[mid] < price) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main(void) {

    // Выручка кафе по дням, руб.
    int revenue[DAYS] = {1500, 2200, 1800, 900, 2600, 3100, 1700, 1200, 2800, 2000};
    printf("Выручка по дням: ");
    print_arr(DAYS, revenue);

    int k = 3;
    printf("Лучшие %d дня подряд: %d руб.\n", k, best_window(DAYS, revenue, k));

    int prefix[DAYS + 1];
    build_prefix(DAYS, revenue, prefix);
    // выручка за дни 2..5 (нумерация с нуля: элементы 1..4)
    printf("Выручка за дни 2..5: %d руб.\n\n", prefix[5] - prefix[1]);

    // Прайс отсортирован, значит можно искать бинарным поиском
    int prices[6] = {79, 89, 199, 450, 640, 1290};
    printf("Товар за 450 руб. - индекс %d\n", binary_search(6, prices, 450));
    printf("Товар за 500 руб. - индекс %d\n", binary_search(6, prices, 500));

    return 0;
}

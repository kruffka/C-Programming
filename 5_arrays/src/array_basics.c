#include <stdio.h>

#define N 8 // чеков за смену в кофейне

void print_checks(int n, const int checks[n]) {
    printf("%d чеков: ", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", checks[i]);
    }
    printf("руб.\n");
}

// Выручка за смену
long long shift_revenue(int n, const int checks[n]) {
    long long total = 0;
    for (int i = 0; i < n; i++) {
        total += checks[i];
    }
    return total;
}

// Самая крупная покупка
int biggest_check(int n, const int checks[n]) {
    int max = checks[0]; // с первого чека, а не с нуля
    for (int i = 1; i < n; i++) {
        if (checks[i] > max) {
            max = checks[i];
        }
    }
    return max;
}

// Развернуть историю: свежие чеки - сверху
void latest_first(int n, int checks[n]) {
    for (int i = 0; i < n / 2; i++) {
        int tmp = checks[i];
        checks[i] = checks[n - 1 - i];
        checks[n - 1 - i] = tmp;
    }
}

int main(void) {

    int checks[N] = {340, 120, 900, 250, 410, 75, 620, 180}; // выручка с чека, руб.
    int n = (int)(sizeof(checks) / sizeof(checks[0]));

    print_checks(n, checks);

    long long revenue = shift_revenue(n, checks);
    printf("Выручка за смену: %lld руб.\n", revenue);
    printf("Средний чек: %.2f руб.\n", (double)revenue / n);
    printf("Самая крупная покупка: %d руб.\n", biggest_check(n, checks));

    // Массив в функцию передать можно, а вернуть - нельзя,
    // поэтому копию делаем поэлементно (report = checks не скомпилируется)
    int report[N];
    for (int i = 0; i < n; i++) {
        report[i] = checks[i];
    }

    latest_first(n, report);
    printf("Отчёт (свежие чеки сверху) - ");
    print_checks(n, report);

    return 0;
}

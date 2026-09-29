#include <stdio.h>

// Считаем не секунды, а число операций: результат не зависит от железа.
// Так в реальных проектах прикидывают, потянет ли сервер лог-файл или картинку.

// O(n)
long long ops_linear(long long n) {
    long long ops = 0;
    for (long long i = 0; i < n; i++) {
        ops++;
    }
    return ops;
}

// O(n^2)
long long ops_quadratic(long long n) {
    long long ops = 0;
    for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < n; j++) {
            ops++;
        }
    }
    return ops;
}

// O(log n): сколько раз число делится пополам
long long ops_logarithmic(long long n) {
    long long ops = 0;
    while (n > 1) {
        n /= 2;
        ops++;
    }
    return ops;
}

// O(n log n): log n проходов по n элементов (так работает merge sort)
long long ops_nlogn(long long n) {
    long long ops = 0;
    for (long long k = n; k > 1; k /= 2) { // log n раз
        ops += n;                          // по n операций
    }
    return ops;
}

int main(void) {

    long long sizes[] = {10, 100, 1000, 5000};
    int count = (int)(sizeof(sizes) / sizeof(sizes[0]));

    printf("%8s %10s %10s %12s %14s\n",
           "n", "O(log n)", "O(n)", "O(n log n)", "O(n^2)");

    for (int i = 0; i < count; i++) {
        long long n = sizes[i];
        printf("%8lld %10lld %10lld %12lld %14lld\n",
               n,
               ops_logarithmic(n),
               ops_linear(n),
               ops_nlogn(n),
               ops_quadratic(n));
    }

    // Для миллиона элементов квадратичный вариант считать замучаешься:
    // это 10^12 операций, а n log n - всего около 2*10^7
    printf("\nfor n = 1000000: n log n ~= 20000000, n^2 = 1000000000000\n");

    return 0;
}

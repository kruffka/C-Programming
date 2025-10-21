#include <stdio.h>

/* 
 * factorial(5) ->
 * 
 * N = 5 и N > 1, возвращаем 5 * factorial(4)
 *                    |
 *                    +-- 4 * factorial(3)
 *                           |
 *                           +-- 3 * factorial(2)
 *                                  |
 *                                  +-- 2 * factorial(1)
 *                                         |
 *                                         +-- 1 * factorial(0)
 *                                                |
 *                                                +-- 1
 * 
 * Раскрытие вычислений:
 * 
 * factorial(5) = 5 * factorial(4)
 *               = 5 * (4 * factorial(3))
 *               = 5 * (4 * (3 * factorial(2)))
 *               = 5 * (4 * (3 * (2 * factorial(1))))
 *               = 5 * (4 * (3 * (2 * (1 * factorial(0)))))
 *               = 5 * (4 * (3 * (2 * (1 * 1))))
 *               = 5 * (4 * (3 * (2 * 1)))
 *               = 5 * (4 * (3 * 2))
 *               = 5 * (4 * 6)
 *               = 5 * 24
 *               = 120
 */

int factorial_non_recursive(int N) {
    int res = 1;
    for (int i = N; i > 1; i--) {
        res = res * i;
    }
    return res;
}

int factorial(int N) {
    if (N < 1) return 1; // условие выхода
    return N * factorial(N - 1); // рекурсия - здесь ф-ия вызывает саму себя, где N-1 = шаг
}


int main() {

    int fact1 = factorial_non_recursive(5);
    int fact2 = factorial(5); // Первый вызов ф-ии с начальным значением 5.   

    printf("fact1 = %d, fact2 = %d\n", fact1, fact2);
}

#include <stdio.h>

/* factorial(5) ->
*                  N = 5 и N > 1, возвращаем 5 * factorial(5 - 1) = 5 * x,
                    где x = factorial(4) = 4 * factorial(3), где
                        factorial(3) = 3 * factorial(2), где
                            factorial(2) = 2 * factorial(1), где
                                factorial(1) = 1 * factorial(0), где вызов factorial(0) вернет 1

                    В итоге получится 5 * x
                                          |
                                        4 * x
                                            |
                                          3 * x
                                              |
                                            2 * x
                                                |
                                              1 * x
                                                  |
                                                  1
*/

// Факториал с помощью рекурсии
int factorial(int N) {
    if (N < 1) return 1; // условие выхода если N < 1. 0! = 1
    return N * factorial(N - 1); // Рекурсивный вызов функции, т.е. функция вызывает сама себя
}

int factorial_non_recursive(int N) {

    int res = 1;
    for (int i = N; i > 1; i--) {
        res = res * i;
    }
    return res;
}

#define N 5

int main(void) {

    printf("%d! = %d\n", N, factorial(N));

    printf("non recursive %d! = %d\n", N, factorial_non_recursive(N));


    return 0;
}

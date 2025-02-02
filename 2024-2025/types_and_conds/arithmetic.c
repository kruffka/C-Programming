#include <stdio.h>

int main(void) {


    int a = 11, b = 5;
    int sum = a + b;
    int mul = a * b;
    int div = a / b;
    int mod = a % b;

    printf("a = %d; b = %d\n", a, b);
    printf("sum = %d, mul = %d, div = %d, mod = %d\n", sum, mul, div, mod);

    a++; // a = a + 1;
    printf("a + 1 = %d\n", a);

    a += 2; // a = a + 2;
    printf("a + 2 = %d\n", a);

    int x = 5, y = 5;
    printf("1. x = %d, y = %d\n", x, y);
    printf("2. x = %d, y = %d\n", x++, ++y);
    printf("3. x = %d, y = %d\n", x, y);
    printf("4. x = %d, y = %d\n", x--, --y);
    printf("5. x = %d, y = %d\n", x, y);

    return 0;
}
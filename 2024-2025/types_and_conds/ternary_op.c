#include <stdio.h>

int main() {

    int a = 5, b = 4;
    printf("a = %d, b = %d\n", a, b);

    // ternary operator
    int max;
    max = a > b ? a : b;
    printf("max is %d\n", max);

    b = 123;
    printf("a = %d, b = %d\n", a, b);

    if (a > b) 
        max = a;
    else 
        max = b;

    printf("max is %d\n", max);

}
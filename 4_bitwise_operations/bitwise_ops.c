#include <stdio.h>

/*
    bitwise operations:
    & - AND
    | - OR
    >>, << - shift
    ~ - bitwise NOT
    ^ - XOR
*/

int main(void) {

    char a = 3, b = 7;

    printf("a = %d, b = %d\n", a, b);
    printf("a & b = %d\n", a & b);
    printf("a | b = %d\n", a | b);
    printf("a ^ b = %d\n", a ^ b);
    printf("~a = %d\n", ~a);
    printf("a << 5 = %d\n", a << 5);
    printf("b >> 2 = %d\n", b >> 2);

}
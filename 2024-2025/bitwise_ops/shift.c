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

    char a;
    char c;

    a = 5;
    c = a >> 1;
    printf("5 >> 1 %d\n", c);

    c = a << 1;
    printf("5 << 1 %d\n", c);
    
    a = -5;
    c = a >> 1;
    printf("-5 >> 1 %d\n", c);
    
    c = a << 1;
    printf("-5 << 1 %d\n", c);


    unsigned b = 0xBAADF00D;
    printf("b >> 24 = 0x%X, (b >> 24) << 8 = 0x%X\n", b >> 24, (b >> 24) << 8);


}

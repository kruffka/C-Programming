#include <stdio.h>

int main(void) {

    int a = 5;
    char ch = 'A'; // 65
    float f = 5.132;
    printf("%d %d\n", a, 1245 + 123);
    printf("%f\n", f);

    // 0111 1111
    // 1000 0000
    char b = 48; // -128 .. 127  0 .. 255
    printf("%c == %d\n", b, b); // '0' == 48

    // overflow
    int my_money = 2147483647;

    printf("my money: %d\n", my_money);
    printf("my_money + 1: %d :(\n", my_money + 1);

    return 0;

}
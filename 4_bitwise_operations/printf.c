#include <stdio.h>

int main(void) {

    char dec_var = 123;
    char hex_var = 0x7b; // or 0x7B
    char oct_var = 0173;
    char bin_var = 0b1111011;

    printf("%d == %d == %d == %d\n", dec_var, hex_var, oct_var, bin_var);

    char a = 18; // 00010010

    printf("hex = %x\n", a);
    printf("dec = %d\n", a);
    printf("oct = %o\n", a);
    printf("bin = ");
    while (a > 0) {
        printf("%d", a & 1);
        a = a >> 1;
    }
    printf("\n");

}
#include <stdio.h>

int main(void) {

    char dec = 123;
    char hex = 0x7b; // or 0x7B
    char oct = 0173;
    char bin = 0b01111011;

    printf("%d == %d == %d == %d\n", dec, hex, oct, bin);

    printf("%d == %d == %d == 0b", dec, hex, oct);


    // в обратном порядке for (int i = 0; i < sizeof(dec)*8 ; i++)
    for (int i = sizeof(dec)*8 - 1; i >= 0 ; i--) {
        printf("%d", (dec >> i) & 1);
    }
    printf("\n");


}
#include <stdio.h>

int main(void) {

    int a = 1234;
    long int b = 123456789L; // L or l 
    unsigned int c = 123456789U; // U or u
    unsigned long int d = 12345678910lu; // LU or lu
    double e = 12.3;
    float f = 5.1f; // F or f
    long double g = 122.88l; // L of l
    char h = '0'; // == 48 ASCII

    printf("a = %d, b = %ld, c = %u, d = %lu, e = %lf, f = %f, g = %Lf, h = %c == %hhd\n", a, b, c, d, e, f, g, h, h);

    int hex = 0x7b, dec = 123, oct = 0173, bin = 0b1111011;

    printf("%d == %d == %d == %d\n", hex, dec, oct, bin);
    printf("0x%x == %d == 0%o == 0b1111011\n", hex, dec, oct);

    return 0;
}
#include <stdio.h>

int main() {

    int a = 0xC0FFEE;
    char *ptr = (char *)&a;

    // для little-endian
    printf("first byte of a = %hhx\n", *ptr); // 0xEE
    ptr++;
    printf("second byte of a = %hhx\n", *ptr); // 0xFF
    ptr++;

    return 0;
}
#include <stdio.h>

#define N 5

int main() {

    int a[5] = {5, 6, 7, 8, 9};
    int b[5] = {1, 2, 3, 4, 5};

    // b = a; // Error
    // a = {5, 3}; // Error
    a[2] = -17; // Ok
    a[0] = b[4]; // Ok
    // a[2.5] = 33; // Error
    // b[4000] = 100; // Error, segfault
    a[-1] = 8; // Ok, possible segfault

    printf("a[-1] = %d\n", a[-1]);

    return 0;
}
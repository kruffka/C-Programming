#include <stdio.h>

int main() {

    int a = 5;
    int *ptr = &a;
    printf("ptr = %p, &ptr = %p, *ptr = %d\n", ptr, &ptr, *ptr);

    *ptr = *ptr + 5;
    printf("ptr = %p, &ptr = %p, *ptr = %d\n", ptr, &ptr, *ptr);

    ptr = ptr + 1; // или ptr++
    printf("ptr = %p, &ptr = %p, *ptr = %d\n", ptr, &ptr, *ptr);

    return 0;
}
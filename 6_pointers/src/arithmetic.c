#include <stdio.h>

int main(void) {

    int a = 5;
    int *ptr = &a;
    printf("ptr = %p, &ptr = %p, *ptr = %d\n", (void *)ptr, (void *)&ptr, *ptr);

    *ptr = *ptr + 5;
    printf("ptr = %p, &ptr = %p, *ptr = %d\n", (void *)ptr, (void *)&ptr, *ptr);

    ptr = ptr + 1; // или ptr++
    printf("ptr = %p, &ptr = %p, *ptr = %d\n", (void *)ptr, (void *)&ptr, *ptr);

    return 0;
}
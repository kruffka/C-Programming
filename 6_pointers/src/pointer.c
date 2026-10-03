#include <stdio.h>

int main(void) {

    char a = 'A'; // = 65
    char *ptr;

    ptr = &a;
    printf("ptr = %p, &a = %p, a = %d\n", (void *)ptr, (void *)&a, a);

    *ptr = 67;
    printf("ptr = %p, &a = %p, *ptr = %d, a = %d\n", (void *)ptr, (void *)&a, *ptr, a);
    return 0;
}
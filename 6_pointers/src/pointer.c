#include <stdio.h>

int main() {

    char a = 'A'; // = 65
    char *ptr;

    ptr = &a;
    printf("ptr = %p, &a = %p, a = %d\n", ptr, &a, a);

    *ptr = 67;
    printf("ptr = %p, &a = %p, *ptr = %d, a = %d\n", ptr, &a, *ptr, a);
    return 0;
}
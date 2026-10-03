#include <stdio.h>

int main(void) {

    char a = 'A';
    char *ptr1;
    char **ptr2; // указатель на указатель на int   

    ptr1 = &a;

    ptr2 = &ptr1;

    printf("ptr2 = %p\n", (void *)ptr2);
    printf("*ptr2 = %p\n", (void *)*ptr2);
    printf("**ptr2 = %c\n", **ptr2);   // A
    printf("&ptr = %p\n", (void *)&ptr2);

    return 0;
}
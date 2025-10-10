#include <stdio.h>

int main() {

    char a = 'A';
    char *ptr1;
    char **ptr2; // указатель на указатель на int   

    ptr1 = &a;

    ptr2 = &ptr1;

    printf("ptr2 = %p\n", ptr2);
    printf("*ptr2 = %p\n", *ptr2);
    printf("**ptr2 = %c\n", **ptr2);   // A
    printf("&ptr = %p\n", &ptr2);

    return 0;
}
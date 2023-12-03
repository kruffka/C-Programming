// GDB and Valgrind example

#include <stdio.h>
#include <stdlib.h> // <malloc.h>

#define SUM(a, b) a + b

int test(int *a, int b) {

    *a = 5;
    b = 5;
}


int main(int argc, char *argv[]) {

    int array[10];
    // segfault
    // array[1000000] = 5;

    int num;
    do {
        printf("Enter a positive integer:");

        scanf("%d", &num);
    } while (num < 0);

    int factorial;
    for (int i = 1; i <= num; i++) {
        factorial = factorial * i;
    }

    printf("%d! = %d\n", num, factorial);

    int a = 1, b = 2;
    printf("before a = %d b = %d\n", a, b);
    test(&a, b);
    printf("after a = %d b = %d\n", a, b);

    int my_sum = SUM(1, 2) * 3;
    printf("my_sum(%d, %d) * 2 = %d\n", a, b, my_sum); // 4?


    // valgrind check here
    int *arr = (int *)malloc(5*sizeof(int));
    // memory leak
    arr = (int *)malloc(10*sizeof(int));

    return 0;
}
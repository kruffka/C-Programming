#include <stdio.h>

int sum(int a, int b) {

    return a + b;

    // тут код никогда не будет выполняться
}

int main(void) {
    
    int a = 5, b = 160;
    int var = sum(a, b);
    printf("my sum is %d\n", var);

    printf("2 + 2 = %d\n", sum(2, 2));
}

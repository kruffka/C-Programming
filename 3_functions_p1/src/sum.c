#include <stdio.h>

int sum(int a, int b) {
    return a + b;
}

int main() {

    int result = sum(1, 2); // вызывается функция sum()
    printf("sum = %d\n", result);

    return 0;
}
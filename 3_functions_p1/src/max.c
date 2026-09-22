#include <stdio.h>

int max(int a, int b); // Объявление (definiton)

int main() {
    int a = 5, b = 2;
    printf("max(%d, %d) = %d\n", a, b, max(a, b));
}

int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}
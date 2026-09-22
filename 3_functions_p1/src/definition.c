#include <stdio.h>

void woof(int n); // Объявление (definiton)

int main() {
    woof(5);
}

void woof(int n) { // Определение (declaration)

    for (int i = 0; i < n; i++) {
        printf("woof\n");
    }
    return;
}
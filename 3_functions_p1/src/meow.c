#include <stdio.h>

void meow(int n) {

    for (int i = 0; i < n; i++) {
        printf("meow\n");
    }
    return; // return для void не обязателен
}

int main() {

    meow(40);

    return 0;
}
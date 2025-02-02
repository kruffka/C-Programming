#include <stdio.h>

#define N 5

int main() {

    int a[N];
    int b[5] = {1, 2, 3, 4, 5};
    float c[] = {1.5, 3.2, 2.5};
    int d[5] = {[3] = 9};
    int e[N] = {0};

    for (int i = 0; i < N; i++) {
        printf("a[%d] = %d\n", i, a[i]);
    }

    return 0;
}
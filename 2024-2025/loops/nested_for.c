#include <stdio.h>

#define N 3
#define M 3

int main() {

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("woof ");
        }
        printf("\n");
    }

    printf("\n");

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", i);
        }
        printf("\n");
    }

    printf("\n");

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }
    return 0;
}
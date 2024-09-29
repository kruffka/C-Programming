#include <stdio.h>

#define N 5
#define M 5

int main() {

    // 1. Вложенный цикл NxM без continue;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }

    printf("\n");
    
    // 2. Вложенный цикл NxM с continue во внутреннем цикле;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (j == 2) continue;
            printf("%d ", j);
        }
        printf("\n");
    }

    printf("\n");

    // 3. Вложенный цикл NxM без continue;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", i);
        }
        printf("\n");
    }

    printf("\n");

    // 4. Вложенный цикл NxM с continue во внешнем цикле;
    for (int i = 0; i < N; i++) {
        if (i == 2) continue;
        for (int j = 0; j < M; j++) {
            printf("%d ", i);
        }
        printf("\n");
    }

    return 0;
}
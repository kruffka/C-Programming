#include <stdio.h>
#include <stdlib.h>
#define N 3

void print_array(char **arr) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {

    char **arr = malloc(N * sizeof(*arr));

    for (int i = 0; i < N; i++) {
        arr[i] = malloc(sizeof(**arr));
        if (arr[i] == NULL) { /* error */ }
        for (int j = 0; j < N; j++) {
            arr[i][j] = 'A' + i; // 'A', 'B'..
        }
    }

    print_array(arr);
    printf("\n");

    **arr = 'X';                // или arr[0][0] = 'X';
    *(*(arr + 1) + 2) = 'Y';    // или arr[1][2] = 'Y';

    print_array(arr);

    for (int i = 0; i < N; i++) {
        free(arr[i]);
        arr[i] = NULL;
    }
    free(arr);
    arr = NULL;

    return 0;
}
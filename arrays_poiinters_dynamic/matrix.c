#include <stdio.h>
#include <malloc.h>

#define N 5
#define M 5

int main() {

    int arr_2d[N][M]; // matrix == 2d array

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            arr_2d[i][j] = i + j;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", arr_2d[i][j]);
        }
        printf("\n");
    }

}
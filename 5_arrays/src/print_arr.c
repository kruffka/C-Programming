#include <stdio.h>

#define N 5
#define M 3

void print_arr(int n, int array[n]) {

    for (int i = 0; i < n; i++) {
        printf("array[%d] = %d\n", i, array[i]);
    }
    printf("\n");
}

int main() {

    int scores[N] = {77, 43, 100, 55, 11};
    print_arr(N, scores);

    int array[M] = {1, 2, 3};
    print_arr(M, array);

    return 0;
}
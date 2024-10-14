#include <stdio.h>

void print_array(int n, int array[]) {
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void bubble_sort(int n, int array[n]) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int tmp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = tmp;
            }
        }
    }
}

int main(void) {

    int A[] = {3, 5, 4, 2, 1};
    const int n = sizeof(A) / sizeof(A[0]);

    print_array(n, A);

    bubble_sort(n, A);

    print_array(n, A);

    return 0;
}
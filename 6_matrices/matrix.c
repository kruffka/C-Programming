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

    int n = 5;
    int *ptr1 = &n;
    int **ptr2 = &ptr1;
    **ptr2 = 2;
    printf("n = %d == %d\n", **ptr2, n);

    // arr_2d => &arr_2d[0] == &arr_2d[0][0]
    printf("%p == %p == %p\n", arr_2d, &arr_2d[0], &arr_2d[0][0]);

    /*
             __________________________________________________________________
	       __|_______________________________________________                  |
		   | |	            							     |                 |
		   | V                                               V                 |
	------|---------------|-------------------------------|---------------|--|---------------|--
	..|   | p |   |   |   |   |   |   |   |   |   |   |   | a |   |   |   |..| s |   |   |   |..
	------|---------------|-------------------------------|---------------|--|---------------|--
	     100 101 102 103 104							 112 113 114 115 116 128 129 130 131 132
	    
        int a = 5;
        int *p = &a;
        int **s = &p;
        **s = 2;

		int* ----> [1, 2, 3]

    int arr[3][3]; 
    0 1 2
    3 4 5
    6 7 8
        int** -----------> int* -> [0, 1, 2]
                           int* -> [3, 4, 5]
        +2*sizeof(int**)-> int* -> [6, 7, 8]
    */

    arr_2d[0][0] = 321;
    printf("**arr = %d *arr[0] = %d arr[0][0] = %d\n", **arr_2d, *arr_2d[0], arr_2d[0][0]);

    printf("arr[2][2] = %d *(*(arr_2d + 2)+2) = %d\n", arr_2d[2][2], *(*(arr_2d + 2)+2));

    int **dyn_arr = (int **)malloc(N*sizeof(int *));
    if (dyn_arr == NULL) {
        printf("Error in malloc %s:%d\n", __FILE__, __LINE__);
        return -1;
    }
    for (int i = 0; i < N; i++) {
        dyn_arr[i] = (int *)malloc(M*sizeof(int));
        if (dyn_arr[i] == NULL) {
            printf("Error in malloc %s:%d\n", __FILE__, __LINE__);
            return -1;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            dyn_arr[i][j] = i;
            printf("%d ", dyn_arr[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < N; i++) {
        free(dyn_arr[i]);
        dyn_arr[i] = NULL;
    }

    free(dyn_arr);
    dyn_arr = NULL;


}
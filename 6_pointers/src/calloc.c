#include <stdio.h>
#include <stdlib.h>

int main() {

    int *arr = calloc(3, sizeof(*arr));           

    if (arr == NULL) {
        printf("Error malloc!\n");
        return -1;
    }

    arr[0] = 123; arr[1] = 2; arr[2] = 3;
    printf("arr[0] = %d, arr[1] = %d, arr[2] = %d\n", arr[0], arr[1], arr[2]);

    free(arr);
    arr = NULL;

    return 0;
}
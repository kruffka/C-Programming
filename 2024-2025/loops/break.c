#include <stdio.h>

// CTRL+C - to stop execution

int main(void) {

    // 1. while
    int i = 0;
    while (i < 5) {
        if (i == 2) {
            break;
        }

        printf("i = %d\n", i);
        i++;
    }
    printf("\n");



    // 2. do while
    int j = 0;
    do {
        if (j == 4) {
            break;
        }

        printf("j = %d\n", j);
        j++;

    } while (j < 5);
    printf("\n");


    // 3. for
    for (int k = 0; k < 5; k++) {
        if (k == 3) {
            break;
        }
        printf("k = %d\n", k);
    }

	return 0;
}
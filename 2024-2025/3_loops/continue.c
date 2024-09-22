#include <stdio.h>

// CTRL+C - to stop execution

int main(void) {

    // 1. while
    int i = 0;
    while (i < 5) {
        i++;
        if (i == 2) {
            continue;
        }

        printf("i = %d\n", i);
    }
    printf("\n");



    // 2. do while
    int j = 0;
    do {
        j++;
        if (j == 4) {
            continue;
        }

        printf("j = %d\n", j);
    } while (j < 5);
    printf("\n");


    // 3. for
    for (int k = 0; k < 5; k++) {
        if (k == 3) {
            continue;
        }

        printf("k = %d\n", k);
    }

	return 0;
}
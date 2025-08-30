#include <stdio.h>

// CTRL+C - to stop execution

int main(void) {

    // 1.
    printf("1: ");
	for (int i = 0; i < 10; i++) {
		printf("%d ", i);
	}
    printf("\n");

    // 2.
    printf("2: ");
    int i = 0;
	for (; i < 10; i++) {
		printf("%d ", i);
	}
    printf("\n");


    // 3.
    printf("3: ");
    int k = 0;
	for (;; k++) {
        if (k >= 10) break;
		printf("%d ", k);
	}
    printf("\n");

    // 4.
    printf("4: ");
    int m = 0;
	for (;;) {
        if (m >= 10) break;
		printf("%d ", m);
        m++;
	}
    printf("\n");

	return 0;
}
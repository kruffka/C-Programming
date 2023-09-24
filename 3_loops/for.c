#include <stdio.h>

// CTRL+C - to stop execution

int main(void) {

    // 1) for loop
	for (int i = 0; i < 5; i = i + 1) { // or --> (int i = 0; i < 5; i++)
		printf("%d ", i);
	}
    printf("\n\n");

    // 2) continue, break;
    int N = 10;
    for (int i = 0; i < N; i++) {
        if (i == 1) continue; // go to next step of loop
        if (i == 8) break;    // stop loop
		printf("i = %d\n", i);
	}
    printf("\n");

    // 3) for variations (;;)
    int i = 0;
    for (;;) {
        if (i >= N) break;
		printf("%d", i);
        i++;
	}

    printf("\n");

	return 0;
}
#include <stdio.h>

// CTRL+C - to stop execution

#define N 5

int main(void) {

	for (int j = 0; j < N; j++) { // j = 0 1 2 .. N - 1
		for (int i = 0; i < N; i++) { // i = 0 1 2 .. N - 1
			printf("#");
		}
		printf("\n");
	}

	return 0;
}

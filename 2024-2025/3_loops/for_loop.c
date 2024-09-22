#include <stdio.h>

// CTRL+C - to stop execution

int main(void) {

	for (int i = 0; i < 5; i = i + 1) { // or --> (int i = 0; i < 5; i++)
		printf("%d ", i);
	}
    printf("\n");

	return 0;
}
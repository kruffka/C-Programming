#include <stdio.h>

// CTRL+C - to stop execution

int main(void) {

	int k = 0; // 5
    // 1) while loop
	while (k < 5) {
		printf("k = %d\n", k);
		k++;
	}
	printf("\n");

    // 2) do while
	k = 0; // 5
	do {
		printf("i = %d\n", k);
        k++;
	} while (k < 5);
	
	return 0;

}
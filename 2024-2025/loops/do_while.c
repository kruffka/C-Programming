#include <stdio.h>

// CTRL+C - to stop execution

int main(void) {

	int k = 0;

	do {
		printf("k = %d\n", k);
        k++;
	} while (k < 5);
	
	return 0;

}
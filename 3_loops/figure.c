#include <stdio.h>

// CTRL+C - to stop execution

#define N 5

int main(void) {

	char ch = 'A'; // ASCII 'A' = 65
	ch = ch + 2; // C == 67
	printf("%d %c\n", ch, ch);

	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N; i++) {
			printf("#");
		}
		printf("\n");
	}

	return 0;
}
// #         # = 1, ' ' = 4 j = 0
// ##        # = 2, ' ' = 3 j = 1
// ###  
// #### 
// #####
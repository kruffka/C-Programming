#include <stdio.h>

// CTRL+C - to stop execution

int main(void) {

	int number = 0;

    do {
        printf("Enter a positive number\n");
        scanf("%d", &number);
        printf("You just entered: %d\n", number);
    } while(number < 0);
	
    printf("Finally, a positive number: %d\n", number);

	return 0;

}
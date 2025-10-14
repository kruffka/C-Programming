#include <stdio.h>
#include <stdlib.h>

int a;
int b = 7;

int main(void) {
	double c;
	short d = 1;

	void *ptr = NULL;
	ptr = malloc(20);

 	printf("a = %d, b = %d, c = %lf, d = %hd, ptr = %p\n", 	            a, b, c, d, ptr);
}

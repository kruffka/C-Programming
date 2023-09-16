#include <stdio.h>

/*
	&& - AND
	|| - OR
	!= - not equal
	== - equal
	>=, <=
*/
int main(void) {

	int a = 10, b = 5;

    if (a > b) {
        printf("a > b\n");
    } else {
        printf("b > a\n");
    }

    if (-1) printf("-1 == true\n");

    // ternary operator
    int max;
    max = a > b ? a : b;
    printf("max is %d\n", max);

	return 0;
}
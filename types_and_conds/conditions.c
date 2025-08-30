#include <stdio.h>

/*
	&& - AND
	|| - OR
	!= - not equal
	== - equal
	>=, <=
	>, <
*/

int main(void) {

	int a = 10, b = 5;
    printf("a = %d, b = %d\n", a, b);

    if (a > b) {
        printf("a > b\n");
    }

    b = 20;
    printf("a = %d, b = %d\n", a, b);

    if (a > b) {
        printf("a > b\n");
    } else {
        printf("a < b\n");
    }

    b = a;
    printf("a = %d, b = %d\n", a, b);

    if (a > b) {
        printf("a > b\n");
    } else if (a < b) {
        printf("a < b\n");
    } else
        printf("a == b\n");

	return 0;
}
#include <stdio.h>

/*
	&& - AND
	|| - OR
	!= - not equal
	== - equal
	>=, <=
	>, <
*/

int main() {

	if (25 < 2); {
        printf("25 < 2!\n");
    }
    // Расскомментируйте else {}, чтобы получить ошибку при компиляции
    // else { printf("25 > 2!\n"); }


    int a = 5;

    if (a < 123)
        printf("a < 123!\n");
        // Расскомментируйте printf(), чтобы получить ошибку при компиляции
        // printf("hello, error\n");
    else if (a != -1)
        printf("a != -1\n");
    else
        printf("a >= 123 && a != 1\n");

    printf("hello, world\n");

	return 0;
}
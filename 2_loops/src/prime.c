#include <stdio.h>

int main(void) {

    int a = 17;

    int i;
    for (i = 2; i < a; i++) {
        if (a % i == 0) {
            break;
        }
    }

    if (i == a) {
        printf("%d <= is a prime number\n", a);
    } else {
        printf("%d <= is not a prime number\n", a);
    }

	return 0;
}
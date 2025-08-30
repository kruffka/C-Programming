#include <stdio.h>

int main(void) {

	int x;
    printf("type x: ");
    scanf("%d", &x);

    switch (x) {
        case 1: { // brackets optional
            printf("one\n");
            break;
        }
        case 2:
            printf("two\n");
            break;
        case 3:
            printf("three\n");
        case 4:
            printf("four\n");
        default:
            printf("default\n");
    }



	return 0;
}
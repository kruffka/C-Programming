#include <stdio.h>

int main(void) {

    int i = 0;
    while (i < 10) {
        printf("i = %d\n", i);

        if (i == 4) {
            break;
        }
        i++;
    }

	return 0;
}
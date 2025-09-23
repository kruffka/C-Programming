#include <stdio.h>

int isEven(int a) {
    return a % 2 == 0 ? 1 : 0;
}

int main() {
    int myNumber = 7;
    int res = isEven(myNumber);
    printf("is myNumber (%d) even? Answer: %d\n", myNumber, res);
}

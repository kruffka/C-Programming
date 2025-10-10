#include <stdio.h>

int main() {

    int scores[3] = {77, 43, 100};
    char ch = 'a';

    printf("scores addresses: [0] = %p, [1] = %p, [2] = %p\n", &scores[0], &scores[1], &scores[2]);
    printf("ch addr = %p\n", &ch);

    return 0;
}
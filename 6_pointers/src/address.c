#include <stdio.h>

int main(void) {

    int scores[3] = {77, 43, 100};
    char ch = 'a';

    printf("scores addresses: [0] = %p, [1] = %p, [2] = %p\n",
           (void *)&scores[0], (void *)&scores[1], (void *)&scores[2]);
    printf("ch addr = %p\n", (void *)&ch);

    return 0;
}
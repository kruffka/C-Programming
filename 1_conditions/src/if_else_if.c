#include <stdio.h>

int main() {
    char c;
    printf("Type 'y' or 'n': ");
    scanf("%c", &c);

    if (c == 'y') {
        printf("yes\n");
    } else if (c == 'n') {
        printf("nope\n");
    } else {
        printf("wrong\n");
    }

    return 0;
}
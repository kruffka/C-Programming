#include <stdio.h>

int main(void) {

    char c1 = 'H';
    char c2 = 'i';
    char c3 = '!';

    printf("%c %c %c\n", c1, c2, c3);
    printf("%d %d %d\n", c1, c2, c3);

    char s[] = "Hi!";
    printf("%s\n", s);
    printf("[%d|%d|%d|%d]\n", s[0], s[1], s[2], s[3]);

    return 0;
}
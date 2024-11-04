#include <stdio.h>

/* 
apt install cowsay

cowsay moo
 _____
< moo >
 -----
        \   ^__^
         \  (oo)\_______
            (__)\       )\/\
                ||----w |
                ||     ||
*/

int main(int argc, char *argv[]) {

    for (int i = 0; i < argc; i++) {
        printf("argv[%d] = %s\n", i, argv[i]);
    }

    printf("Bootleg cow says:\n");
    printf(" _____\n< %s >\n -----\n        \\   ^__^\n         \\  (oo)\\_______\n            (__)\\       )\\/\n                ||----w |\n                ||     ||\n", argv[1]);
}
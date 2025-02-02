#include <stdio.h>

char max(char symb1, char symb2) {
    if (symb1 > symb2) {
        return symb1;
    } else {
        return symb2;
    }
}

int main(void) {
    
    char ch1 = 'A', ch2 = 'a';
    printf("'%c' = %d, '%c' = %d, max is '%c'\n", ch1, ch1, ch2, ch2, max(ch1, ch2));
}

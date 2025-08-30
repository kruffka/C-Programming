#include <stdio.h>

int main(void) {

    char words[2][5] = {"Hi!", "Bye!"};
    // Первая строка "Hi!"
    printf("%s\n", words[0]);

    // Первая строка "Bye!"
    printf("%s\n", words[1]);

    // Первая строка по символам
    printf("%c%c%c\n", words[0][0], words[0][1], words[0][2]);

    // Вторая строка по символам
    printf("%c%c%c%c\n", words[1][0], words[1][1], words[1][2], words[1][3]);
    
    return 0;
}
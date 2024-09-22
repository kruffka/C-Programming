#include <stdio.h>

// Примеры с возможными ошибками при использовании логических операторов

int main() {

    // =

    int a = 5;
    printf("a = %d\n", a);

    if (a = 6) { // a == 6?
        printf("6 == a!\n");    
    }
    printf("a = %d\n", a);

    // != || !=

#define GREEN 1
#define ORANGE 2
#define RED 3
#define BLACK 4

    int color = ORANGE;
    if (color != RED || color != GREEN) { // always true
        printf("1. true\n");
    } else {
        printf("1. false\n");
    }

    // == && ==
    color = GREEN;

    if (color == RED && color == GREEN) { // always false
        printf("2. true\n");
    } else {
        printf("2. false\n");
    }

    // == || !=
    if (color == RED || color != GREEN) {
        printf("3. true\n");
    } else {
        printf("3. false\n");
    }

    // == && !=
    if (color == RED && color != BLACK) {
        printf("4. true\n");
    } else {
        printf("4. true\n");
    }



}
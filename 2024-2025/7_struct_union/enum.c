#include <stdio.h>

enum colors {
  RED, // по умолчанию 0
  GREEN, // = 1
  BLUE = 5,
  ORANGE // = 6
};

int main() {
    enum colors my_color = GREEN;

    switch (my_color) {
        case RED:
            printf("RED\n");
            break;
        case GREEN:
            printf("GREEN\n");
            break;
        default:
            printf("Error\n");
    }
    
}
#include <stdio.h>

int main(void) {

    // Выравнивание
    int a = 12345;
    printf("|%7d|\n", a);
    printf("|%-7d|\n", a);

    // Кол-во знаков после запятой
    float f = 0.1 + 0.2;
    double d = 0.1 + 0.2;
    printf("f is %.17lf, d is %.17f\n", f, d);
    
    return 0;
}
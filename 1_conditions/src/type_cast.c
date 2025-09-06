#include <stdio.h>

int main() {

    // Неявное (implicit) приведение типов
    int x = 5;
    double y = 12.3;
    y = x;
    x = y;

    double z = x / 2;
    printf("z = %lf\n", z);

    // Явное (explicit) приведение типов
    int a = 5;
    double b = 12.3;
    b = (double)a;
    a = (int)b;

    double c = (double)a / 2;
    printf("c = %lf\n", c);

    return 0;
}
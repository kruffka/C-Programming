// При компиляции слинковать с математикой: -lm

#include <stdio.h>
#include <math.h>

double f(double x) {
    return exp(-x * x);
}

double pi(double a, double b, int n) {

    double h = (b - a) / n;
    double s = 0.0;
    for (int i = 0; i < n; i++) {
        s += f(a + h * (i + 0.5));
    }

    s *= h;
    return s * s; // т.к. e^(-x^2) дает нам корень Пи
}

int main(void) {

    double a = -5.;
    double b = 5.0;
    int n = 100000000;

    printf("Start integration for %d points with 1 thread [%lf, %lf]\n", n, a, b);

    printf("my   pi = %.12lf\n", pi(a, b, n));
    printf("math pi = %.12lf\n", M_PI);

    return 0;
}
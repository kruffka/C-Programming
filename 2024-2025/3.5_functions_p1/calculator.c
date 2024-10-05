#include <stdio.h>
#include <math.h>

double power(double base, double exp) {
    double answer = 1;
    for (int i = 0; i < exp; i++) {
        answer = answer * base;   
    }
    return answer;
}

double my_sqrt(double x);

double sum(double a, double b) {
    double sum_ab = a + b;
    return sum_ab;
}

double mul(double a, double b) {
    return a * b;
}

int main(void) {
    double a, b;
    char s;

    printf("Input: ");
    scanf("%lf%c%lf", &a, &s, &b);
    printf("%lf %c %lf = ", a, s, b);

    switch(s) {
        case '+':
            printf("%lf", sum(a, b));
            break;
        case '-':
            printf("%lf", a - b);
            break;
        case '*':
            printf("%lf", mul(a, b));
            break;
        case '/':
            printf("%lf", a / b);
            break;
        case '^':
            printf("%lf", power(a, b));
            break;
        case '$': // Корень обоих чисел
            printf("%lf %lf", my_sqrt(a), my_sqrt(b));
            break;        
        default:
            printf("\nError: Unknown operator '%c'", s);
    }
    printf("\n");

    return 0;
}

/*
sqrt для целых x пример:
x = 16
left = 0, right = x
1 итерация:
middle = (left + right) / 2

| 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 |
  ^                               ^                                      ^
  |                               |                                      |
left                            middle                                  right

middle*middle < x ? no: right = middle

2 итерация
=
| 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |
  ^               ^               ^
  |               |               |
left            middle          right

middle*middle < x ? no: right = middle

3 итерация:

| 0 | 1 | 2 | 3 | 4 |
  ^       ^       ^
  |       |       |
left    middle   right

middle*middle < x ? yes: left = middle

4 итерация:
|  2  |  3  |  4  |
  ^      ^     ^
  |      |     |
left   middle  right

... ближе к 26 итерации left станет равен 4.000, что и будет ответом


*/

#define SQRT_PRECISION 32

double my_sqrt(double x) {
    
    if (x < 0) {
        return NAN; // Not A Number 0.0f/0.0f;
    }
    double left = 0, right = x + 1; // + 1 для 0 < x < 1, т.к. их корень больше самого x
    for (int i = 0; i < SQRT_PRECISION; i++) {
        double middle = (left + right) / 2;
        
        if (middle * middle < x) {
            left = middle;
        } else {
            right = middle;
        }
    }
    
    return left;
    
}
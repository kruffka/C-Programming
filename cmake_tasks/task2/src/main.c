#include <stdio.h>
#include <static.h>
#include <dynamic.h>

void main() {

    int a = sum_from_static_lib(2, 2);
    double b = div_from_dynamic_lib(5.0, 2);

    printf("a = %d; b = %lf\n", a, b);
}
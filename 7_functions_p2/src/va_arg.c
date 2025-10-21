#include <stdio.h>
#include <stdarg.h>

// Становится более мощным инструментом при использовании совместно с макросами
int my_log_print(char *format, ...) {
    va_list args;

    va_start(args, format);

    int arg = va_arg(args, int);
    double f_arg = va_arg(args, double);

    printf("args = %d %lf\n", arg, f_arg);
    // ...

    va_end(args);

    return 0;
}

int main(void) {

    my_log_print("%d %f\n", 123, 555.42);
}
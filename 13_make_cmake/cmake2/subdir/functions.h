#include <stdio.h>
#include <stdlib.h>

#define RED     "\033[1;31m"
#define RESET   "\033[0m" // == in hex "\x1B[0m"
#define BLACK   "\e[0;30m"
#define WHITE   "\e[0;37m"

typedef struct complex {
    int re;
    int im;
} complex_t;

// typedef struct complex complex_t;

complex_t init();
complex_t* init2();
void free_struct(complex_t *a);

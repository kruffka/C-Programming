#include "functions.h"

struct complex init() {

    complex_t a;
    a.im = 4;
    a.re = 5;
    return a;
}

complex_t* init2() {

    complex_t *a = (complex_t *)malloc(sizeof(complex_t));

    return a;
}

void free_struct(complex_t *a) {

    free(a);
}
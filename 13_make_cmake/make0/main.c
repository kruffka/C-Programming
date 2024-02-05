#include "functions.h"

// Для сборки сделать make
// Запускать ./main

void main() {

    printf("This is " RED "red" RESET " color\n");
    printf("This is %sred %scolor\n", RED, RESET);
    printf("This is \033[1;31mred \033[0mcolor\n");
    printf("This is \033[1;31mred color without reset\n");
    printf("This is \033[1;31mred \033[0;32mgreen \033[0;36mcyan\n");

    printf("\033[33;44myellow on blue" RESET "\n");
    printf(BLACK "BLACK" WHITE "WHITE" RESET "\n");

    struct complex p = init();

    printf("re %d im %d\n", p.re, p.im);

#if TEST_DEF
    printf("test_def is %d\n", TEST_DEF);
#endif
    complex_t *pointer = init2();

    (*pointer).re = 2;
    pointer->re = 2;
    
    free_struct(pointer);


}
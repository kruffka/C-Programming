#include "header.h"

void my_print(int num_to_print) {
    printf("[%s:%d] NUM: %d\n", __FILE__, __LINE__, num_to_print);
}

int sum(int a, int b) {
    return a + b;
}
#include <stdio.h>
#include "log.h"

#define YELLOW "\e[0;33m"
#define RED "\e[0;31m"
#define GREEN "\e[0;32m"
#define BLUE "\e[0;34m"
#define RESET "\e[0m"

// Моя простая функция для логирования
void my_log(log_type_e type, char *str, char *file, int line) {

    if (type >= END) {
        return;
    }
    char *color_array[END] = {GREEN, YELLOW, RED, BLUE};
    printf("[%s:%d] %s%s"RESET, file, line, color_array[type], str);
}

// Моя простая функция для логирования
void my_log2(log_type_e type, char *type_s, char *str) {

    if (type >= END) {
        return;
    }
    char *color_array[END] = {GREEN, YELLOW, RED, BLUE};
    printf("[%s] %s%s"RESET, type_s, color_array[type], str);
}

// Моя простая функция для логирования
void my_print(char *str, char *color) {

    printf("%s%s"RESET, color, str);
}


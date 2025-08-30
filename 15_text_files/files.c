#include <stdio.h>
#include <stdlib.h>

// gcc files.c -o files
// ./files file.m output

// Функции для чтения/записи символов/строк
// fgetc, fgets, getc, getchar
// fputc, fputs, putc, putchar, puts

// fprintf/fscanf - функции для записи/чтения в файл с определенными форматом (аналог printf/scanf)

// fgetpos, fseek, fsetpos, ftell, rewind - для управления позиции в файле

int main(int argc, char *argv[]) {

    if (argc < 3) {
        printf("Usage: ./executable file.m output\n");
        exit(1);
    }
    short re, im;

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("In %s:%d Error opening file\n", __FILE__, __LINE__);
        exit(1);
    }

    FILE *file_w = fopen(argv[2], "w");
    if (file_w == NULL) {
        printf("In %s:%d Error opening file\n", __FILE__, __LINE__);
        exit(1);
    }

    fscanf(file, "array = ");

    while (!feof(file)) {
        fscanf(file, "%hd + j*(%hd)\n", &re, &im);
        printf("%hd + j*(%hd)\n", re, im);
        fprintf(file_w, "%hd + j*(%hd)\n", re, im);
    }


    fclose(file);

    return 0;
}
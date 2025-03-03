#include <stdio.h>
#include <stdlib.h>

// gcc text.c -o text
// ./text file.txt out.txt

int main(int argc, char *argv[]) {

    if (argc < 3) {
        printf("Usage: ./a.out file.txt out.txt\n");
        exit(1);
    }
    short re, im;

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    FILE *file_w = fopen(argv[2], "w");
    if (file_w == NULL) {
        printf("In %s:%d Error opening file\n", __FILE__, __LINE__); // или perror()
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
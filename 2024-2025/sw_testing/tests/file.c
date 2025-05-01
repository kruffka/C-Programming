#include <stdio.h>

// Пример с файлом
int count_lines_in_file(const char *filename) {
    if (!filename) return -1;
    
    FILE *file = fopen(filename, "r");
    if (!file) return -2;
    
    int lines = 0;
    char ch = fgetc(file);
    if (ch == EOF) {
        return 0;
    }
    
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') lines++;
    }
    
    fclose(file);
    return lines + 1; // +1 для последней строки без \n
}

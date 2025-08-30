#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// gcc binary.c -o binary
// ./binary bin.pcm

#define N 10

struct some_data {
    int value;
    char str[10];
};

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("Usage: ./executable bin.pcm\n");
        exit(1);
    }

    FILE *file = fopen(argv[1], "wb");
    if (file == NULL) {
        printf("In %s:%d Error opening file\n", __FILE__, __LINE__);
        exit(1);
    }

    struct some_data array[N];
    printf("Writing to binary file..\n");
    for (int i = 0; i < N; i++) {
        // заполним случайно
        array[i].value = rand();
        sprintf(array[i].str, "%d", rand());

        fwrite(&array[i], sizeof(struct some_data), 1, file); // запись по одной структуре за раз
        
        printf("[%d] value %d str %s\n", i, array[i].value, array[i].str);

    }

    fclose(file);

    // Очистим исходный массив
    memset(array, 0, sizeof(*array));

    file = fopen(argv[1], "rb");
    if (file == NULL) {
        printf("In %s:%d Error opening file\n", __FILE__, __LINE__);
        exit(1);
    }
    printf("Reading from binary file..\n");
    // читаем одной строкой из бинарного файла N раз sizeof(struct some_data)
    fread(array, sizeof(struct some_data), N, file); // запись по одной структуре за раз
    
    printf("[%d] value %d str %s\n", 0, array[0].value, array[0].str);

    printf("[%d] value %d str %s\n", N-1, array[N-1].value, array[N-1].str);

    fclose(file);

    return 0;
}
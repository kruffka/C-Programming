#include <stdio.h>
#include <stdlib.h>

// Смотрим на своё же адресное пространство (Linux: /proc/self/maps).
// Видно, где лежат код, данные, стек и куча - адреса только виртуальные.

int global_var = 7; // Data

int main(void) {

    const char *literal = "строка лежит в read-only секции";
    int local_var = 42;          // стек
    int *heap_var = malloc(sizeof(*heap_var)); // куча

    if (heap_var == NULL) {
        printf("Error malloc!\n");
        return 1;
    }
    *heap_var = 123;

    printf("адрес строкового литерала = %p\n", (void *)literal);
    printf("адрес global_var         = %p\n", (void *)&global_var);
    printf("адрес local_var (стек)   = %p\n", (void *)&local_var);
    printf("адрес heap_var (куча)    = %p\n", (void *)heap_var);

    printf("\nпервые строки /proc/self/maps:\n");
    FILE *f = fopen("/proc/self/maps", "r");
    if (f == NULL) {
        printf("не получилось открыть /proc/self/maps (нужен Linux)\n");
    } else {
        char line[256];
        for (int i = 0; i < 5 && fgets(line, sizeof(line), f) != NULL; i++) {
            printf("%s", line);
        }
        fclose(f);
    }

    free(heap_var);
    heap_var = NULL;

    return 0;
}

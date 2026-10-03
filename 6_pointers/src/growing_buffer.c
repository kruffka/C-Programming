#include <stdio.h>
#include <stdlib.h>

// Сообщение из чата: сколько в нём байт - заранее неизвестно,
// поэтому буфер растёт сам, по мере поступления символов.
// Так же устроены std::string в C++, StringBuilder в Java, list в Python.

int main(void) {

    const char *incoming = "Привет! Это сообщение пришло целиком, но его длину заранее никто не знал.";

    size_t cap = 8; // сколько байт выделено
    size_t len = 0; // сколько уже занято
    char *msg = malloc(cap);
    if (msg == NULL) {
        printf("Error malloc!\n");
        return 1;
    }

    for (const char *p = incoming; *p != '\0'; p++) {
        if (len + 1 == cap) { // +1 - место под '\0'
            char *tmp = realloc(msg, cap * 2);
            if (tmp == NULL) {
                free(msg);
                return 1;
            }
            msg = tmp;
            cap *= 2;
            printf("буфер вырос до %zu байт\n", cap);
        }
        msg[len++] = *p;
    }
    msg[len] = '\0';

    printf("В буфере: %s\n", msg);
    printf("Занято байт: %zu (включая '\\0'), выделено: %zu\n", len + 1, cap);

    free(msg);
    msg = NULL;

    return 0;
}

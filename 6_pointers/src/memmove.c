#include <stdio.h>
#include <string.h>

// История поиска: удаляем самый старый запрос и сдвигаем остальные влево.
// Области памяти перекрываются, поэтому memcpy тут не подойдёт - нужен memmove.

void print_history(int n, const char *items[n]) {
    for (int i = 0; i < n; i++) {
        printf("  %d: %s\n", i + 1, items[i]);
    }
}

int main(void) {

    const char *history[5] = {"кофе", "пицца", "кино", "такси", "книга"};
    int n = 5;

    printf("история поиска:\n");
    print_history(n, history);

    // сдвигаем элементы 1..n-1 на одну позицию влево
    memmove(history, history + 1, (size_t)(n - 1) * sizeof(*history));
    n--;

    printf("\nпосле удаления первого запроса:\n");
    print_history(n, history);

    return 0;
}

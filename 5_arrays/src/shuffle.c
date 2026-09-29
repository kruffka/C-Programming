#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK 52

void print_deck(int n, const int deck[n]) {
    for (int i = 0; i < n; i++) {
        printf("%3d", deck[i]);
        if ((i + 1) % 13 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

// Тасование Фишера-Йетса: честно перемешиваем массив на месте
void shuffle(int n, int deck[n]) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1); // случайный индекс от 0 до i включительно
        int tmp = deck[i];
        deck[i] = deck[j];
        deck[j] = tmp;
    }
}

int main(void) {

    srand(time(NULL));

    // Колода карт (или плейлист из 52 треков)
    int deck[DECK];
    for (int i = 0; i < DECK; i++) {
        deck[i] = i + 1;
    }

    printf("До тасования:\n");
    print_deck(DECK, deck);

    shuffle(DECK, deck);

    printf("\nПосле тасования (каждый запуск - своя перестановка):\n");
    print_deck(DECK, deck);

    // ТАК НЕ НАДО: менять arr[i] со случайным из ВСЕГО массива.
    // Часть перестановок получится чаще других - распределение перекошено.
    // Именно на такой перекос жаловались пользователи музыкальных сервисов.

    return 0;
}

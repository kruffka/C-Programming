#include <stdio.h>

#define SENSORS 5
#define SUBJECTS 3

void print_arr(int n, const int values[n], const char title[]) {
    printf("%s: ", title);
    for (int i = 0; i < n; i++) {
        printf("%d ", values[i]);
    }
    printf("\n");
}

int main(void) {

    int temp[SENSORS] = {-5, -2, 0, 3, 1}; // датчики на улице, C
    print_arr(SENSORS, temp, "Температура по датчикам");

    int scores[SUBJECTS] = {5, 4, 3}; // оценки за семестр
    print_arr(SUBJECTS, scores, "Оценки");

    return 0;
}

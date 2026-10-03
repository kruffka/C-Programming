#include <stdio.h>
#include <stdlib.h>

// Таблица оценок студентов: и число студентов, и число предметов
// известны только в рантайме - статический массив тут не подойдёт.

void print_grades(int students, int subjects, int **grades) {
    for (int i = 0; i < students; i++) {
        for (int j = 0; j < subjects; j++) {
            printf("%3d", grades[i][j]);
        }
        printf("\n");
    }
}

int main(void) {

    int students = 3;
    int subjects = 4;

    // сначала массив указателей на строки
    int **grades = malloc(students * sizeof(*grades));
    if (grades == NULL) {
        printf("Error malloc!\n");
        return 1;
    }

    // затем сама каждая строка
    for (int i = 0; i < students; i++) {
        grades[i] = malloc(subjects * sizeof(**grades));
        if (grades[i] == NULL) {
            printf("Error malloc!\n");
            return 1;
        }
    }

    // заполняем оценки (3, 4 или 5)
    for (int i = 0; i < students; i++) {
        for (int j = 0; j < subjects; j++) {
            grades[i][j] = 3 + (i + j) % 3;
        }
    }

    printf("Оценки (строки - студенты, столбцы - предметы):\n");
    print_grades(students, subjects, grades);

    // средний балл каждого студента
    for (int i = 0; i < students; i++) {
        int sum = 0;
        for (int j = 0; j < subjects; j++) {
            sum += grades[i][j];
        }
        printf("Средний балл студента %d: %.2f\n", i + 1, (double)sum / subjects);
    }

    // освобождаем в порядке, обратном выделению
    for (int i = 0; i < students; i++) {
        free(grades[i]);
        grades[i] = NULL;
    }
    free(grades);
    grades = NULL;

    return 0;
}

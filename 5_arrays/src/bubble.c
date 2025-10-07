#include <stdio.h>

#define N 5

void bubble_sort(int size, int arr[size]) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) { // если текущий > следующего, то делаем swap - меняем местами
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

void print_array(int size, int array[size]) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {

    int array[N] = {6, -5, 3, 77, 4};
    // Выводим изначальный массив
    print_array(N, array);

    // Сортируем по возрастанию
    bubble_sort(N, array);

    // Вот они все, слева-направо..
    print_array(N, array);

    return 0;
}
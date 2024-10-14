#include <stdio.h>

void print_array(int n, int array[]) {
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void print_matrix(int n, int m, int matrix[n][m]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void delete_k_elem_array(int k, int n, int array[]) {
    array[k] = 0;
    for (int i = k; i < n; i++) {
        array[i] = array[i + 1];
    }
}

void print_string(char string[]);

int main(void) {

    int array[5] = {1, 2, 3, 4, 5};
    int array2d[3][3] = {{1, 2, 3},
                         {4, 5, 6},
                         {7, 8, 9}};

    char string[] = "some text";

    print_array(5, array);
    printf("\n");

    print_matrix(3, 3, array2d);
    printf("\n");

    print_string(string); // Тоже самое что делает puts() и printf("%s")
    printf("\n");

    // Функция зануляем элемента массива под вторым индексом и двигает все элементы на один влево
    delete_k_elem_array(4, 5, array);
    print_array(5, array);


}

void print_string(char string[]) {
    int n = 0;
    while (string[n] != '\0') {
        printf("%c", string[n]);
        n++;
    }
    printf("\n");
}
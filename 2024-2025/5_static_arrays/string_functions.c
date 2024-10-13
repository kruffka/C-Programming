#include <stdio.h>
#include <string.h> // Для работы с функциями обработки строк

int main(void) {

    char str1[128] = "hello";
    char str2[128] = "bye bye";

    puts(str1); // Вывод на экран строки str1
    puts(str2); // Вывод на экран строки str2

    int n = strlen(str1);    // Длина строки, не включая '\0'
    printf("strlen of str1 is %d\n", n);
    
    strcpy(str1, "privet"); // копирование "privet" в str1
    puts(str1); // Вывод на экран строки str1

    strncpy(str2, str1, sizeof(str1));  // Копирование str1 в str2, но размер не более sizeof(str1)

    if (strcmp(str1, str2) == 0) {  // Сравнение двух строк
        printf("str1 is equal to str2\n"); // 0 если строки идентичны
    } else {
        // Положительное число – если строки отличаются и код первого отличающегося символа в строке str1 больше кода символа на той же позиции в строке str2.
        // Отрицательное число – если строки отличаются и код первого отличающегося символа в строке str1 меньше кода символа на той же позиции в строке str2.
        printf("str1 is not equal to str2\n");
    }

    strcat(str1, str2); // Функция добавляет строку source_str к строке destination_str. При этом первая строка должна быть достаточно большая, чтобы вместить вторую строку
    printf("str after cat is: %s\n", str1);

    puts("Input some string:");
    char input_str[256];
    fgets(input_str, sizeof(input_str), stdin); // Ввод с клавиатуры строки в input_str, максимальный размер 256 символов
    printf("Your string: %s", input_str); // Вывод на экран строки input_str

    return 0;
}
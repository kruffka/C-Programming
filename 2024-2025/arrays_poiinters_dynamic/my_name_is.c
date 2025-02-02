#include <stdio.h>

int main() {

    char name[20];
    printf("[fgets] Enter name: ");
    fgets(name, sizeof(name), stdin); // Считает с клавиатуры не более sizeof(name) байт
    printf("My name is %s", name);

    // Может быть переполнение массива, а также scanf не считывает строку через пробел
    // printf("[scanf] Enter name: ");
    // scanf("%s", name); 
    // printf("Your name is %s\n", name);

}
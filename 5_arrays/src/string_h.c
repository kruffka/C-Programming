#include <stdio.h>
#include <string.h>

int main(void) {

    char login[128] = "ivan";

    printf("Логин: %s\n", login);
    printf("Длина логина: %zu\n", strlen(login));

    strcpy(login, "student"); // логин сменили на другой
    printf("Новый логин: %s\n", login);

    // Собираем email: копируем логин и дописываем домен
    char email[128];
    strncpy(email, login, sizeof(email));
    email[sizeof(email) - 1] = '\0'; // strncpy может не закрыть строку
    strncat(email, "@sibguti.ru", sizeof(email) - strlen(email) - 1);
    printf("Email: %s\n\n", email);

    // Проверка пароля при входе
    char saved[64]   = "qwerty123";
    char entered[64] = "qwerty123";
    if (strcmp(saved, entered) == 0) {
        puts("Пароль верный");
    } else {
        puts("Пароль неверный");
    }

    // Ввод имени с клавиатуры
    char name[64];
    puts("\nВведите имя:");
    fgets(name, sizeof(name), stdin);

    size_t len = strlen(name);
    if (len > 0 && name[len - 1] == '\n') {
        name[len - 1] = '\0'; // срезаем перевод строки от fgets
    }
    printf("Привет, %s!\n", name);

    return 0;
}

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int my_strlen(const char s[]) {
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;
}

void my_strcpy(char dest[], const char src[]) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0'; // обязательно закрываем строку
}

int count_char(const char s[], char target) {
    int count = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == target) {
            count++;
        }
    }
    return count;
}

void to_upper(char s[]) {
    for (int i = 0; s[i] != '\0'; i++) {
        s[i] = (char)toupper(s[i]);
    }
}

void reverse(char s[]) {
    int n = my_strlen(s);
    for (int i = 0; i < n / 2; i++) {
        char tmp = s[i];
        s[i] = s[n - 1 - i];
        s[n - 1 - i] = tmp;
    }
}

int is_palindrome(const char s[]) {
    int i = 0;
    int j = my_strlen(s) - 1;

    while (i < j) {
        char left  = (char)tolower(s[i]);
        char right = (char)tolower(s[j]);
        if (left != right) {
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}

int main(void) {

    char login[64] = "ivan_petrov";
    printf("Длина логина: %d (strlen = %zu)\n", my_strlen(login), strlen(login));

    char login_copy[64];
    my_strcpy(login_copy, login); // копия для базы данных
    printf("Копия для БД: %s\n", login_copy);

    char feedback[64] = "Good coffee, thanks!";
    printf("Букв 'o' в отзыве: %d\n", count_char(feedback, 'o'));
    printf("Пробелов в отзыве: %d\n", count_char(feedback, ' '));

    to_upper(login); // логин в верхнем регистре для логов
    printf("Логин для логов: %s\n", login);

    char nick[32] = "kayak"; // ник-палиндром
    printf("Ник \"%s\" - палиндром? %d\n", nick, is_palindrome(nick));

    char tag[32] = "coffee"; // тег, который надо развернуть
    reverse(tag);
    printf("Тег наоборот: %s\n", tag);

    printf("Пароль \"Level\" - палиндром? %d\n", is_palindrome("Level"));

    return 0;
}

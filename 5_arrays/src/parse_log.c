#include <stdio.h>
#include <string.h>

// Строки в реальном мире: разбираем строку лога, как это делает любая
// система мониторинга. Формат строки: время уровень сообщение

#define MAX_LINE 128

int main(void) {

    const char *log = "12:04:35 ERROR не удалось открыть файл базы данных";

    char line[MAX_LINE];
    // копируем, потому что strtok меняет строку на месте
    snprintf(line, sizeof(line), "%s", log);

    char *time = strtok(line, " ");
    char *level = strtok(NULL, " ");
    char *message = strtok(NULL, ""); // всё, что осталось целиком

    printf("время:     %s\n", time);
    printf("уровень:   %s\n", level);
    printf("сообщение: %s\n", message);

    if (strcmp(level, "ERROR") == 0) {
        printf("\nэто ошибка - её стоит отдать дежурному отдельным списком\n");
    }

    return 0;
}

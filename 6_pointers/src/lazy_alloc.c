#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Виртуальная память выделяется сразу, а физическая - только когда в неё пишут.
// Проверяем по счётчику VmRSS из /proc/self/status (Linux).

long rss_kb(void) {
    FILE *f = fopen("/proc/self/status", "r");
    if (f == NULL) {
        return -1;
    }
    char line[256];
    long kb = -1;
    while (fgets(line, sizeof(line), f) != NULL) {
        if (strncmp(line, "VmRSS:", 6) == 0) {
            sscanf(line + 6, "%ld", &kb);
            break;
        }
    }
    fclose(f);
    return kb;
}

int main(void) {

    const size_t MB = 1024 * 1024;
    const size_t size = 128 * MB;

    printf("в начале процесса:              %ld КБ физической памяти\n", rss_kb());

    char *big = malloc(size); // пока только виртуально
    if (big == NULL) {
        printf("Error malloc!\n");
        return 1;
    }
    printf("после malloc(128 МБ):          %ld КБ (физически ещё ничего)\n", rss_kb());

    memset(big, 1, size); // первое обращение к страницам
    printf("после записи во все 128 МБ:    %ld КБ (вот теперь страницы пришли)\n", rss_kb());

    free(big);
    big = NULL;

    return 0;
}

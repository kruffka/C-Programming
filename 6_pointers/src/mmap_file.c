#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>

// Файл можно подключить к своему адресному пространству (mmap) и работать с ним
// как с обычным массивом. Страницы подтягиваются с диска по мере обращения -
// тем же page fault, что и в lazy_alloc.c. Держать весь файл в памяти не нужно.

int main(void) {

    const char *path = "/tmp/c_pointers_mmap.bin";
    const long size = 100L * 1024 * 1024; // 100 МБ

    // Готовим файл на 100 МБ и ставим метку ровно в середине.
    FILE *out = fopen(path, "wb");
    if (out == NULL) {
        printf("Error fopen!\n");
        return 1;
    }
    fseek(out, size / 2, SEEK_SET);
    fputc('Y', out);
    fseek(out, size - 1, SEEK_SET);
    fputc('\n', out);
    fclose(out);

    // Подключаем файл к памяти. Сами данные с диска при этом не читаются.
    int fd = open(path, O_RDONLY);
    if (fd == -1) {
        printf("Error open!\n");
        return 1;
    }

    char *data = mmap(NULL, (size_t)size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (data == MAP_FAILED) {
        printf("Error mmap!\n");
        close(fd);
        return 1;
    }

    // Читаем байт из середины файла. Пришла только одна страница, а не все 100 МБ.
    printf("байт из середины файла: %c\n", data[size / 2]);

    // То же самое видно в списке отображённых участков памяти.
    FILE *maps = fopen("/proc/self/maps", "r");
    if (maps != NULL) {
        char line[512];
        while (fgets(line, sizeof(line), maps) != NULL) {
            if (strstr(line, path) != NULL) {
                printf("отображение из /proc/self/maps:\n%s", line);
                break;
            }
        }
        fclose(maps);
    }

    munmap(data, (size_t)size);
    close(fd);
    unlink(path);

    return 0;
}

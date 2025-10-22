#include <stdio.h>


void func() {
    printf("Error at LINE=%d, FILE=%s, function=%s\n", __LINE__, __FILE__, __FUNCTION__);

    printf("%s:%d\n", __FILE__, __LINE__); // позволяет в VSCode прыгнуть в этот файл зажав CTRL + лкм по этой ссылке
}

int main() {
    printf("Compilation time: date=%s, time=%s\n", __DATE__, __TIME__);

    func();
    return 0;
}
#include <stdio.h>

// CTRL+C - to stop execution

int main() {

    int i = 0;

    // 1. printf выведет i = 5
    while (i < 5)
        i++;
        printf("i = %d\n", i);


    // 2. Если расскомментировать printf, то будет ошибка при компиляции
    do
        i++;
        // printf("i = %d\n", i)
    while (i < 5);

    // 3. Выведет i = 0,1,2,3,4 в цикле, а затем вне цикла один раз i = 6, проинициализированную в самом начале
    for (int i = 0; i < 5; i++)
        printf("i = %d\n", i);
        printf("i = %d\n", i);


}
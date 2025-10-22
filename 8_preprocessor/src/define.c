#include <stdio.h>

#define ADD(a, b) a + b
#define MIN(a, b) ((a < b) ? a : b)

#define K 123 // K определена как 123

void func() {
    printf("K = %d\n", K); // K == 123
}

#undef K // а теперь K больше не существует

int main() {
    // printf("K = %d\n", K); // ошибка: K больше не существует
    func();

    // MIN(1, 2) раскроется на 1 этапе компиляции как: ((1 < 2) ? (1 : 2)) и будет равно 1
    printf("MIN(1, 2) = %d\n", MIN(1, 2));

    int a = 5, b = 3;
    int c = ADD(a, b); // чему равна c?
    int d = 4 * ADD(a, b); // чему равна d?
    printf("a = %d, b = %d, c = %d, d = %d\n", a, b, c, d);
    return 0;
}
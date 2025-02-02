#include <stdio.h>
#include <stdlib.h>

float test_func1(float a, int b) {
    return (a + b) * (a - b);
}

float test_func2(float a, int b) {
    return b * b - 4 * a;
}

float test_func3(float a, int b) {
    return 25 * (a - b);
}

float test_func_default(float a, int b) {
    return (a + b);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: ./program F_num\n");
        return -1;
    }

    float (*function_ptr)(float, int); // Указатель на функцию, которая возвращает тип float и аргументами float, int

    switch (atoi(argv[1])) {
        case 1:
            function_ptr = &test_func1; // или просто имя функции
            printf("Set func ptr to test func1\n");
            break;
        case 2:
            function_ptr = &test_func2;
            printf("Set func ptr to test func2\n");
            break;
        case 3:
            function_ptr = test_func3;
            printf("Set func ptr to test func3\n");
            break;
        default:
            function_ptr = test_func_default;
            printf("Set func ptr to test_func_default\n");
    }
    
    // вызываем функцию, которую выбрал пользователь при запуске
    float res = function_ptr(5.2, 2);
    printf("function_ptr ret = %f addr of func() = %p\n", res, function_ptr);


    // Массив указателей на функцию
    float (*fun_ptr[])(float, int) = {test_func1, test_func2, test_func3, test_func_default}; // Указатель на функцию, которая возвращает тип float и аргументами float, int

    for (int fun = 0; fun < sizeof(fun_ptr) / sizeof(fun_ptr[0]); fun++) {
        res = fun_ptr[fun](5.2, 2);
        printf("fun_ptr ret = %f addr of func() = %p\n", res, fun_ptr[fun]);
    }
    
}
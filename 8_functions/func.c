#include <stdio.h>

int sum(int a, int b) {

    return a + b;

    // тут
}

void test1(int a, int *p) {

    a = 5;
    *p = 5;

}

void test2(int N, int *arr) { // *arr or arr[]
    arr[0] = 123;
}

void test3(int N, int arr[][3]) { // **arr - dynamic; arr[][size] - static
    arr[0][0] = 123;
}

void test4(int a, int b);

int main(int argc, char *argv[]) { // todo argc argv[] example
    
    if (argc < 2) {
        printf("Usage: ./func arg\n");
        return 1;
    }
    printf("Nof args %d, arg0 is %s, arg1 is %s\n", argc, argv[0], argv[1]);

    int a = 1;
    int b = 1;

    int sum_var = sum(a, b);
    printf("my sum is %d %d\n", sum(a, b), sum_var);


    int *p = &b;
    test1(a, &b);
    printf("a = %d b = %d\n", a, b);

    const int N = 3;
    int arr_1d[N];
    test2(N, arr_1d); // arr_1d == &arr_1d[0]
    printf("test2 = %d\n", arr_1d[0]);


    int arr_2d[N][N];
    test3(N, arr_2d); // arr_2d == &arr_2d[0][0] == arr_2d[0]
    printf("test3 = %d\n", arr_2d[0][0]);



    int (*fun_ptr)();
    fun_ptr = sum;

    printf("fun_ptr res = %d\n", fun_ptr(a, b));


    test4(0, 0);

}

void test4(int a, int b) {

    printf("This is %s %d %s\n", __FUNCTION__, __LINE__, __FILE__);
}

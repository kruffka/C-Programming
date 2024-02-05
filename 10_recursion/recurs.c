#include <stdio.h>

#define E 10e-4

int f(int n) {
    if (n <= 1) {
        return 1;
    }

    return f(n - 1) * n;
}

//       f(3)
//         |
//     f(2)*3
//       |
//   f(1)*2
//     |
//     1

int main() {


    // 5! = 1 * 2 * 3 * 4 * 5
    int factorial = 1;
    for (int n = 1; n <= 5; n++) {
        factorial *= n;
    }
    printf("5! = %d\n", factorial);

    int fact = 1;
    for (int n = 5; n != 0; n--) {
        fact = fact * n;
    }

    printf("factorial = %d %d\n", f(5), fact);


    return 0;

}
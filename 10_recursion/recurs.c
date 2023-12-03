#include <stdio.h>

int factorial(int n) {
    
    if (n == 0) 
        return 1;
    else
        return factorial(n - 1) * n;
}


int main() {


    int fact = 1;
    for (int n = 5; n != 0; n--) {
        fact = fact * n;
    }

    printf("factorial = %d %d\n", factorial(5), fact);


    return 0;

}

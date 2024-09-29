#include <stdio.h>

void meow() {

    printf("meow\n");
    printf("meow\n");
    printf("meow\n");

}

void woof_n_times(int n) {

    for (int i = 0; i < n; i++) {
        printf("woof!\n");
    }

}

int main() {
    
    meow();
    
    int n = 5;
    woof_n_times(n);

    return 0;
}
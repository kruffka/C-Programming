#include <stdio.h>

void meow() {

    printf("meow\n");
    printf("meow\n");
    printf("meow\n");

}

void woof_nxn_times(int n) {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("woof ");
        }
        printf("\n");
    }

}

int main() {
    
    meow();
    
    int n = 5;
    woof_nxn_times(n);

    return 0;
}
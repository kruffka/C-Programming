#include <stdio.h>

#define PRINT_DEBUG(format, ...)                                                                        \
	do {                                                                                                \
            printf("%s:%d:%s(): " format,  __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__);             \
    } while(0)

int sum(int x, int y) {
    int sum = x + y;
#ifdef DEBUG
    // этот код будет скомпилирован только если DEBUG определен
    printf("DEBUG: Value of x = %d\n", x);
    printf("DEBUG: Value of y = %d\n", y);
    printf("DEBUG: Sum calculated as %d\n", sum);
#endif
    return sum;
}

#if B == 5
    int a = 555;
#else
    int a = -1;
#endif

int main() {
    printf("a = %d\n", a);

    int res = sum(6, 7);

    if (1) { // error
        char message[] = "some error explanation";
        PRINT_DEBUG("Error: %s\n", message); // ; точка с запятой обязательно
    } else {
        // ..
    }
    return 0;
}
#include <stdio.h>

union test_union {
	char a;
	int b;
};

int main() {
    union test_union test = {0};
    test.a = 'A';
    printf("test.a = %d, b = %d\n", test.a, test.b);

    test.b = 12345;
    printf("test.a = %d, b = %d\n", test.a, test.b);
}
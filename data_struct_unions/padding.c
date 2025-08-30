#include <stdio.h>

struct test1 {
	char a;
	int b;
	char c;
	int d;
	char e;
	int f;	
};

struct test2 {
	int b;
	int d;
	int f;
	char a;
	char c;
	char e;
};

int main(void) {
	printf("sizeof test1 = %ld, test2 = %ld\n", sizeof(struct test1), sizeof(struct test2));
	
}
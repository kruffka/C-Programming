#include <stdio.h>
#include <stdlib.h>

char *f() {
	char s = 'A';
    printf("f.s = %p %c\n", &s, s);

	return &s; // warning: function returns address of local variable [-Wreturn-local-addr]
}

int main() {
	// Пример 1
	char *a = f();
    printf("main.a = %p\n", a);
    // printf("main.*a = %p\n", *a); // segfault?
    	
	// Пример 2
	int *b = malloc(sizeof(int));
    *b = 555;
    printf("malloc.b = %p %d\n", b, *b);

	free(b);
    printf("free.b = %p %d\n", b, *b); // мусор в *b

}

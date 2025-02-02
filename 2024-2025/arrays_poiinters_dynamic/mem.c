#include <stdio.h>
#include <stdlib.h>

// 1. gcc mem.c -c
// nm mem.o
// objdump -D mem.o
// 2. gcc mem.c
// nm a.out
// objdump -D a.out


int a; // пойдет в BSS и будет равна 0, т.к. не инициализирована и является глобальной
int b = 7; // пойдет в секцию DATA, т.к. глобальная и инициализирована

int main(void) {
	double c; // будет лежать в секции STACK
	short d = 1; // будет лежать в секции STACK

	void *ptr = NULL; // будет лежать в секции STACK
	ptr = malloc(20); // указатель указывает на память из секции HEAP

 	printf("a = %d, b = %d, c = %lf, d = %hd, ptr = %p\n",
            a, b, c, d, ptr);
}

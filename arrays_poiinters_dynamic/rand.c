#include <stdio.h> // для printf()
#include <stdlib.h> // Для rand()
#include <time.h> // для time()

int rand_int(int min, int max) {
	return (rand() % (max - min + 1)) + min;
}
int main() {
    // Указываем seed для псевдорандома и в качестве аргумента передаем текущее время
	srand(time(NULL));
	printf("Unix timestamp = %ld random num = %d\n",  time(NULL), rand_int(-100, 100));
}

#include <stdio.h>

typedef struct cats {
	int age;
	char name[64];
} cats_t;

typedef unsigned int uint;

int main(void) {

    cats_t cats = {3, "Mango"}; // тоже самое что и struct cats cats = {3, "Mango"};
    printf("cats.age = %d, cats.name = %s\n", cats.age, cats.name);

    uint a = 5; // Тоже самое что и unsigned int a = 5;
    printf("a = %u\n", a);

	return 0;
}
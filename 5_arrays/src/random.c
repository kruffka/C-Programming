#include <stdio.h>
#include <stdlib.h> // Для rand()
#include <time.h> // для time()

// Unix время https://www.unixtimestamp.com/

int main() {

    printf("rand() = %d\n", rand()); // всегда 1804289383

    // Указываем seed для псевдорандома и в качестве аргумента передаем текущее время
	srand(time(NULL)); // достаточно сделать 1 раз
	printf("Unix timestamp = %ld\n",  time(NULL)); // Unix timestamp
    printf("Random [0..99] = %d\n", rand() % 100); // Случайное число от 0 до 99

    return 0;
}
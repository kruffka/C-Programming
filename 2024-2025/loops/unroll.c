#include <stdio.h>

// CTRL+C - to stop execution

#define N 1000000000

// Оригинальный цикл
// for (int i = 0; i < N; i++) { sum = sum + i; }


int main(void) {

    long long unsigned int sum = 0;

    // Первый вариант с раскруткой цикла
	for (int i = 0; i < N/2; i++) {
		sum = sum + i;
        sum = sum + N/2 + i;
	}
	
    // Второй вариант с раскруткой цикла
	// for (int i = 0; i < N; i += 2) {
	// 	sum = sum + i;
    //     sum = sum + i + 1;
	// }

    printf("sum is %llu\n", sum);


    return 0;
}
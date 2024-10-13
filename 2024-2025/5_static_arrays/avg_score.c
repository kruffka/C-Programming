#include <stdio.h>

float average(int len, int array[]) {
	int sum = 0;
	for (int i = 0; i < len; i++) {
		sum += array[i];
	}
	return (float)sum / len;
}

int main(void) {

	int test1_score = 77;
	int test2_score = 100;
	int test3_score = 42;

	float avg_score = (test1_score + test2_score + test3_score) / 3.0;

	printf("test1 score = %d\n", test1_score);
	printf("test2 score = %d\n", test2_score);
	printf("test3 score = %d\n", test3_score);
	printf("1. avg score = %.2f\n", avg_score);

	const int len = 3;
	int test_score[len];
	test_score[0] = 77;
	test_score[1] = 100;
	test_score[2] = 42;

	int sum = 0;
	for (int i = 0; i < len; i++) {
		printf("test%d score = %d\n", i, test_score[i]);
		sum += test_score[i];
	}
	printf("2. avg score = %.2f\n", (float)sum / len);

	printf("3. avg score with func = %.2f\n", average(len, test_score));

}
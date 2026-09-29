#include <stdio.h>

#define N 3

int main(void) {

    int score1 = 77;  // Паша
    int score2 = 43;  // Маша
    int score3 = 100; // Даша

    // Деление на 3.0f, а не на 3: иначе целочисленное деление даст 73 вместо 73.33
    float avg1 = (score1 + score2 + score3) / 3.0f;
    printf("Scores: %d, %d, %d; avg = %.2f\n", score1, score2, score3, avg1);

    // Теперь то же самое, но с массивом
    int scores[N] = {77, 43, 100};

    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += scores[i];
    }
    float avg2 = (float)sum / N;
    printf("Scores: %d, %d, %d; avg = %.2f\n", scores[0], scores[1], scores[2], avg2);

    return 0;
}
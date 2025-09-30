#include <stdio.h>

int main() {

    int score1 = 77; // Паша
    int score2 = 43; // Маша
    int score3 = 100; // Даша

    float avg1 = (score1 + score2 + score3) / 3;
    printf("Scores: %d, %d, %d; avg = %f\n", score1, score2, score3, avg1);

    // С массивами
    int scores[3] = {77, 43, 100};
    float avg2 = (scores[0] + scores[1] + scores[2]) / 3;
    printf("Scores: %d, %d, %d; avg = %f\n", scores[0], scores[1], scores[2], avg2);

    return 0;
}
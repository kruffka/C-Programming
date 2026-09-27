#include <stdio.h>

int find_max(int arrSize, int scores[arrSize]) {

    int max = scores[0];
    for (int i = 1; i < arrSize; i++) {
        if (max < scores[i]) {
            max = scores[i];
        }
    }
    return max;
}

int main() {

    int scores[] = {77, 43, 100, 55, 11};
    int arrSize = sizeof(scores) / sizeof(scores[0]);

    printf("max is %d\n", find_max(arrSize, scores));

    return 0;
}
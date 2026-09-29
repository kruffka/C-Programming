#include <stdio.h>

#define H 4
#define W 4

void print_matrix(int h, int w, int m[h][w]) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            printf("%4d", m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Размытие 3x3: каждый пиксель -> среднее арифметическое соседей
void blur(int h, int w, int src[h][w], int dst[h][w]) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            int sum = 0;
            int count = 0;

            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {
                    int ni = i + di;
                    int nj = j + dj;
                    // за границами матрицы не читаем
                    if (ni >= 0 && ni < h && nj >= 0 && nj < w) {
                        sum += src[ni][nj];
                        count++;
                    }
                }
            }
            dst[i][j] = sum / count;
        }
    }
}

int main(void) {

    // Фото (яркость пикселей): 200 - блик,
    // после размытия он расползётся по соседям
    int src[H][W] = {
        {10, 20, 30, 40},
        {50, 200, 60, 70},
        {80, 90, 100, 110},
        {120, 130, 140, 150}
    };

    int dst[H][W];

    print_matrix(H, W, src);
    blur(H, W, src, dst);
    print_matrix(H, W, dst);

    return 0;
}

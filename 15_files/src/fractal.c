#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// gcc fractal.c -o fractal -lm
// ./fractal

// mp4:
// ffmpeg -framerate 30 -i frame_%03d.ppm -c:v libx264 -pix_fmt yuv420p fractal_zoom.mp4
// rm frame_*.ppm


void save_frame(int frame, int width, int height) {
    char filename[32];
    sprintf(filename, "frame_%03d.ppm", frame);
    FILE *f = fopen(filename, "wb");
    fprintf(f, "P6\n%d %d\n255\n", width, height);

    // Параметры зума: плавно приближаемся к интересной точке
    double zoom = 1.0 / (1.0 + pow(frame, 1.5) * 0.5);
    double target_x = -0.743643887037151;
    double target_y = 0.131825904205330;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Преобразование координат пикселя в комплексную плоскость
            double dx = (x - width / 2.0) * 4.0 * zoom / width + target_x;
            double dy = (y - height / 2.0) * 4.0 * zoom / height + target_y;

            double a = dx, b = dy;
            int iter;
            for (iter = 0; iter < 256; iter++) {
                double a2 = a * a, b2 = b * b;
                if (a2 + b2 > 4.0) break;
                b = 2.0 * a * b + dy;
                a = a2 - b2 + dx;
            }

            // Раскраска на основе количества итераций
            unsigned char r = (iter * 7) % 255;
            unsigned char g = (iter * 3) % 255;
            unsigned char b_val = (iter * 11) % 255;
            
            fputc(r, f); fputc(g, f); fputc(b_val, f);
        }
    }
    fclose(f);
}

int main() {
    int total_frames = 120; // 4 секунды видео при 30 fps
    for (int i = 0; i < total_frames; i++) {
        save_frame(i, 640, 480);
        printf("Frame %d/120 done\n", i);
    }
    return 0;
}

#include <stdio.h>
#include <sys/stat.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct pixel {
    uint8_t r; // unsigned char r;
    uint8_t g;
    uint8_t b;
} pixel_t;

#define HEADER_SIZE (54)

int main(int argc, char *argv[]) {

    if (argc < 3) {
        printf("Usage: ./prog img_in.bmp img_out.bmp\n");
        exit(1);
    }

    FILE *orig_file = fopen(argv[1], "rb");
    if (orig_file == NULL) {
        perror("error opening orig_file");
        exit(1);
    }

    FILE *new_file = fopen(argv[2], "wb");
    if (new_file == NULL) {
        perror("error opening new_file");
        exit(1);
    }

    struct stat st;
    fstat(fileno(orig_file), &st);
    int nof_pixels = (st.st_size - HEADER_SIZE) / 3;
    printf("nof_pixels = %d\n", nof_pixels);
    
    // Заголовок
    char header[HEADER_SIZE];
    fread(header, 1, sizeof(header), orig_file);
    fwrite(header, 1, sizeof(header), new_file);

    pixel_t pixel;

    for (int i = 0; i < nof_pixels; i++) {
        fread(&pixel, sizeof(pixel), 1, orig_file);
        if (i < 10000) { // i % 2 == 0
#if 0
            printf("r %hhu g %hhu b %hhu\n", pixel.r, pixel.g, pixel.b);
#endif
            pixel.r = 0;
            pixel.g = 255;
            pixel.b = 60;
        } else {
            pixel.r = 176;
        }
        fwrite(&pixel, sizeof(pixel), 1, new_file);
    }
    
    printf("done: new file in %s\n", argv[2]);
    fclose(orig_file);
    fclose(new_file);

    return 0;
}
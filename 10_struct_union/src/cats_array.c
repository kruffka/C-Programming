#include <stdio.h>

struct funny {
  char name[128];
  char *fate;
};

void print_cats(struct funny cats[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Cat[%d/%d]: Name: %s, fate: %s\n", i + 1, n,
            cats[i].name, cats[i].fate);
    }
}

int main(void) {
    struct funny cats[] = {{"Yaqub Qomarudin Dibizah", "👑"},
                            {"Khalid Kashmiri", "🗡️"},
                            {"Khidir Karawitah", "⚔️"},
                            {"Ismail Ahmad Khan Nabawi", "🐎"},
                            {"Utsman Abdul Jalil Shisha", "📚"},
                            {"Muhammad Sumbul", "♐"}};

    print_cats(cats, sizeof(cats)/sizeof(cats[0]));

}
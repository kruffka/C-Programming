#include <stdio.h>

struct cat {
	char *name;
	int age;
};

void print_cats(struct cat cats[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Cat[%d]: Name: %s, Age: %d\n", i,
            cats[i].name, cats[i].age);
    }
}

int main(void) {
    struct cat cats[] = {{ "Tom", 5 }, { .name = "Felix", .age = 4 }, {"Mango", 3}};

    print_cats(cats, 3);

}
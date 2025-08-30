#include <stdio.h>

struct cat {
	char *name;
	int age;
};

void print_cat(struct cat cat) {
	printf("Name: %s, Age: %d\n", 
		cat.name, cat.age);
}

int main(void) {
    struct cat tom = { "Tom", 5 };

    struct cat felix = { .name = "Felix", .age = 4 };

    struct cat mango;
    mango.name = "Mango";
    mango.age = 3;

    print_cat(tom);
    print_cat(felix);
    print_cat(mango);

}
#include <stdio.h> 

int main(void) { 

    int x = 12;
    int y = 7;
    double z1 = x / y; // implicit (неявное)
    double z2 = (double)x / y; // explicit (явное)

	printf("z1 is %lf and z2 is %lf\n", z1, z2); 

	return 0; 
}

#include <stdio.h>

struct byte {
	unsigned char b0:1;
	unsigned char b1:1;
	unsigned char b2:1;
    unsigned char b3:1; 
    unsigned char b4:1; 
    unsigned char b5:1; 
    unsigned char b6:1; 
    unsigned char b7:1; 	
};

int main(void) 
{
    char a = 0b00010001; // 17
    printf("a = %d\n", a);

    struct byte *bits;
    bits = (struct byte *)&a;

    bits->b0 = 0; // 0 бит числа a
    printf("a = %d\n", a);
}

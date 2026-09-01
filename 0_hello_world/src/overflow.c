#include <stdio.h>

int main()
{
    unsigned int money = 2147483648;
    printf("You can get %u$ or double and pass it on to next person\n", money);
    printf("double of money is %u$\n", money * 2);
    return 0;
}
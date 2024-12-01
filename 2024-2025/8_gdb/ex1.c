#include <stdio.h>  

int f(int x){   
    int y = x * 10;   
    return y;  
}
int main(){   
    int k = 5, l;   
    l = f(k);
    printf("l = %d\n",l);   
    return 0;  
}   

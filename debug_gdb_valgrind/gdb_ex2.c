#include <stdio.h>  
#define N 10  
int main()  
{  
    int arr[N];      
    unsigned i;  
    for (i = N - 1; i >= 0; --i) {          
        arr[i] = i;  
        printf("%d ", arr[i]);  
    }      
    return 0;  
}  

#include <stdio.h>  
#include <stdlib.h>  
int char_cmp(const void* a, const void* b)  
{  
    return *(const char*)a - *(const char*)b;  
}  
int main() {  
    char greeting[] = "Hello!";      
    qsort(greeting, sizeof(greeting) - 1, sizeof(*greeting), char_cmp);      
    printf("%s\n", greeting);      
    return 0;  
}  

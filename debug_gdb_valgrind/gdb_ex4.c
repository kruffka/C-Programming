#include <stdio.h>  
#define QUOTE_(WHAT) #WHAT 
#define QUOTE(WHAT) QUOTE_(WHAT)  
#define CSC_TRACE(format, ...) \
    printf("%s: "format, __FILE__":"QUOTE(__LINE__), \
    ## __VA_ARGS__)  
void f() {
    int answer = 42;
    CSC_TRACE("the answer is %d\n", answer);
}
int main() {
    f();
    return 0;
}

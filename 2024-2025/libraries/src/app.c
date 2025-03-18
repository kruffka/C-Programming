#include "log.h"

#define PURPLE "\e[0;35m"

int main(void) {

    my_print("print info\n", PURPLE);

    MY_LOG(INFO, "hello, info!\n");
    MY_LOG(WARNING, "hello, warning!\n");
    MY_LOG(ERROR, "hello, error!\n");
    MY_LOG(DEBUG, "hello, debug!\n");

    MY_LOG2(INFO, "log2 info\n");
    MY_LOG2(WARNING, "log2 warn\n");

    return 0;
}
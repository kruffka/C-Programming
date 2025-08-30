#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <stdint.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <pthread.h>

void read_pipe(int p, char *b, int size) {
    printf("read_pipe\n");
  while (size) {
    int ret = read(p, b, size);

    if (ret <= 0) exit(0);

    b += ret;
    size -= ret;
  }
}
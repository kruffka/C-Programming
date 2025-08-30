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

void write_pipe(int p, char *b, int size) {
    printf("write_pipe\n");

  while (size) {
    int ret = write(p, b, size);

    if (ret <= 0) exit(0);

    b += ret;
    size -= ret;
  }
}
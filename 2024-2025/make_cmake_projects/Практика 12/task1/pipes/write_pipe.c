#include "pipes.h"

void write_pipe(int p, char *b, int size) {

  while (size) {
    int ret = write(p, b, size);

    if (ret <= 0) exit(0);

    b += ret;
    size -= ret;
  }
}
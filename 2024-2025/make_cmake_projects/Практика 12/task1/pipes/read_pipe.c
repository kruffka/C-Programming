#include "pipes.h"

void read_pipe(int p, char *b, int size) {

  while (size) {
    int ret = read(p, b, size);

    if (ret <= 0) exit(0);

    b += ret;
    size -= ret;
  }
}
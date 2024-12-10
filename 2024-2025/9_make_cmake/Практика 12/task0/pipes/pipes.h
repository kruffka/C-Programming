#ifndef _PIPES_H_
#define _PIPES_H_

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

void write_pipe(int p, char *b, int size);
void read_pipe(int p, char *b, int size);

#endif // #ifndef _PIPES_H_

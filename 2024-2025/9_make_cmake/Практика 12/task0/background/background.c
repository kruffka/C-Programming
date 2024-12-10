#include <stdio.h>
#include "background.h"
#include "pipes.h"

static int command_pipe_read;
static int command_pipe_write;
static int result_pipe_read;
static int result_pipe_write;

int module_initialized = 0;

void background_system_msg(const char *msg) {
  int len = strlen(msg) + 1;
  int ret;
  char command[MAX_COMMAND+1];

  // while (1) {
    write_pipe(command_pipe_write, (char *)&len, sizeof(int));
    write_pipe(command_pipe_write, (char *)msg, len);
    read_pipe(result_pipe_read, (char *)&ret, sizeof(int));
  // }
}

void background_system_process(void) {
  int len;
  int ret;
  char command[MAX_COMMAND+1];

  // while (1) {
    read_pipe(command_pipe_read, (char *)&len, sizeof(int));
    read_pipe(command_pipe_read, command, len);
    ret = system(command);
    write_pipe(result_pipe_write, (char *)&ret, sizeof(int));
  // }
}

void start_background_system(void) {
  int p[2];
  pid_t son;

  if (module_initialized == 1)
    return;

  module_initialized = 1;

  if (pipe(p) == -1) {
    perror("pipe");
    exit(1);
  }

  command_pipe_read  = p[0];
  command_pipe_write = p[1];

  if (pipe(p) == -1) {
    perror("pipe");
    exit(1);
  }

  result_pipe_read  = p[0];
  result_pipe_write = p[1];
  son = fork();

  if (son == -1) {
    perror("fork");
    exit(1);
  }

  if (son) {
    close(result_pipe_write);
    close(command_pipe_read);
    return;
  }

  close(result_pipe_read);
  close(command_pipe_write);
  background_system_process();
}
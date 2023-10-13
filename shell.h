#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>

#define BUFF_SIZE 1024

char *get_input();
void exec(__attribute__((unused)) char **buff);

#endif

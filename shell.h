#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include<sys/wait.h>
#include <string.h>
char *get_input(char *);
void exec(__attribute__((unused)) char **buff);

#endif

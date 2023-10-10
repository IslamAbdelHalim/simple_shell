#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include<sys/wait.h>

char *get_input(void);
int exec(char *buff);

#endif

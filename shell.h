#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>

#define DELIMETER " \t\n"
#define BUFF_SIZE 1024
/*point to environment variable*/
extern char **environ;

/*All String Function*/
int _strlen(char *str);
char *_strdup(char *str);

/*allocation memory*/
void freeArrStr(char **str);

char *get_input();
char **parse_input(char *buff);
void exec(char **arguments, char **argv);

#endif

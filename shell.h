#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>

#define DELIMETER " \t\n"
#define BUFF_SIZE 1024
/*point to environment variable*/
extern char **environ;

/*All String Function*/
int _strlen(char *str);
char *_strdup(char *str);
int _strcmp(char *str1, char *str2);
char *_strcat(char *str1, char *str2);
char *_strcpy(char *str1, char *str2);

/*allocation memory*/
void freeArrStr(char **str);
void rev_string(char *str, int len);
void _error(char *program, char *commend, int index);
char *_itoa(int num);


char *get_input();
char **parse_input(char *buff);
int exec(char **arguments, char **argv, int index);
char *getTheEnv(char *varName);
char *getThePath(char *cmd);
void print_env();

#endif

#include "shell.h"

char *get_input()
{
	char *buff = NULL;
	size_t n = 0;

	getline(&buff, &n, stdin);
	return (buff);
}

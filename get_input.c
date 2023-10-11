#include "shell.h"

char *get_input(char *buffer)
{
	char *buff = NULL;
	size_t n = 0, x;

	x = getline(&buff, &n, stdin);
	if (x <= 0)
		return (NULL);
	buffer = strtok(buff, "\n");
	if (buffer == NULL)
		return (NULL);
	return (buffer);
}

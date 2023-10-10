#include "shell.h"

int get_input()
{
	char *buff;
	size_t n;
	int bytes;

	buff = (char *)malloc(sizeof(char));
	n = 1;
	bytes = getline(&buff, &n, STDIN_FILENO);
	return (bytes);
}

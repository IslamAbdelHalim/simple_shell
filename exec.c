#include "shell.h"

int exec(char *buff)
{
	const char *buffer = buff;
	char *const x[2] = {buff, NULL};
	execve(buffer, x, NULL);
	return (0);
}

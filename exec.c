#include "shell.h"

void exec(__attribute__((unused)) char **buff)
{
	const char *buffer = buff[0];
	r = execve(buffer, buff, NULL);
	perror("./shell");
	exit(1);
}

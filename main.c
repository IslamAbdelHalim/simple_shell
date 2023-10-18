#include "shell.h"

int main()
{
	int w;
        pid_t pid;
	char *buff, *buffer = NULL;

	while (1)
	{
		w = write(STDOUT_FILENO, "#Simple_Shell$ ", 15);
		if (w == -1)
			return (1);
		pid = fork();
		if (pid == 0)
		{
			buff = get_input(buffer);
			buff[1] = NULL;
			exec(buff);
		}
		else
			wait(NULL);
	}
	return (0);
}

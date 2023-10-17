#include "shell.h"

/**
 * exec - function that execute the command
 *
 * @arguments: The array of arguments commend
 *
 * @argv: The array of parameters from input
*/

void exec(char **arguments, char **argv)
{
	int r;
	pid_t pid;
	char *buffer = arguments[0];

	if (buffer == NULL)
	{
		perror(argv[0]);
		freeArrStr(arguments);
	}

	/*Create a child process*/
	pid = fork();
	if (pid == 0)
	{
		r = execve(buffer, arguments, environ);
		if (r == -1)
		{
			perror(argv[0]);
			freeArrStr(arguments);
			exit(1);
		}
	}
	else
	{
		wait(NULL);
	}
}

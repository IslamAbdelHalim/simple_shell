#include "shell.h"

/**
 * exec - function that execute the command
 *
 * @arguments: The array of arguments commend
 *
 * @argv: The array of parameters from input
 *
 * @index: The counter
 *
 * Return: The exit value
*/

int exec(char **arguments, char **argv, int index)
{
	int r;
	pid_t pid;
	int stat;
	char *buffer = getThePath(arguments[0]);

	if (buffer == NULL)
	{
		_error(argv[0], buffer, index);
		return (127);
	}

	/*Create a child process*/
	pid = fork();
	if (pid == 0)
	{
		r = execve(buffer, arguments, environ);
		if (r == -1)
		{
			freeArrStr(arguments);
			free(buffer);
			exit(1);
		}
	}
	else
	{
		waitpid(pid, &stat, 0);
		free(buffer);
		stat = WEXITSTATUS(stat);
	}

	return (stat);
}

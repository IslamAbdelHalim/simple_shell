#include "shell.h"

/**
 * main - Entry point
 *
 * Return: 0 if sucess
*/

int main(void)
{
	char *buff; /*The input*/
	pid_t pid; /*process id*/
	char **argv; /*The array of argument*/
	int argc, i;
	char del[] = {" "}; /*delimeter*/
	char *tokens;

	while (1)
	{
		/*print a promt*/
		write(STDOUT_FILENO, "#Simple_Shell$ ", 15);
		/*Create a process*/
		pid = fork();
		wif (pid == 0)
		{
			/*Get the input*/
			buff = get_input(buff);
			/*Parse the input*/
			tokens = strtok(buff, del);
			argc = 0;
			argv = malloc(sizeof(char *) * 100);
			while (tokens != NULL)
			{
				argv[argc] = malloc(sizeof(char) * (strlen(tokens) + 1));
				strcpy(argv[argc], tokens);
				argc++;
				tokens = strtok(NULL, del);
			}
			printf("%s", argv[0]);
			exec(argv);
			for (i = 0; i < argc; i++)
			{
				free(argv[i]);
			}
			free(argv);
		}
		else
			wait(NULL);
	}
	return (0);
}

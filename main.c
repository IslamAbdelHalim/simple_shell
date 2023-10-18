#include "shell.h"

/**
 * main - Entry point
 *
 * @argc: The arguemnt count
 *
 * @argv: The array of arrgumnt
 *
 * Return: 0 if sucess
*/

int main(int argc, char *argv[])
{
	char *buff; /*The input*/
	char **arguments; /*The array of argument*/
	int stat = 0, i = 0;
	(void)argc;

	while (1)
	{
		/*Get The Input*/
		buff = get_input();
		if (buff == NULL)
		{
			free(buff);
			return (stat);
		}
		i++;

		/*parse the input*/

		arguments = parse_input(buff);
		if (arguments == NULL)
		{
			continue;
		}
		/*Handle env*/
		if (_strcmp(arguments[0], "env") == 0)
		{
			print_env();
			freeArrStr(arguments);
			continue;
		}
		if (_strcmp(arguments[0], "exit") == 0)
		{
			freeArrStr(arguments);
			stat = WEXITSTATUS(stat);
			exit(stat);
		}
		/*execution the command*/
		exec(arguments, argv, i);
		/*free the array of arguments*/
		freeArrStr(arguments);
	}
	return (0);
}

#include "shell.h"

/**
 * get_input - function to get input and put it into array
 *
 * Return: Array of argument
*/

char *get_input()
{
	char *buff;
	size_t n = BUFF_SIZE;
	ssize_t x, i = 0, bksp = 0;

	/*Print The Prompt*/
	if (isatty(0))
		write(1, "#shell$ ", 8);
	buff = malloc(sizeof(char) * BUFF_SIZE);
	if (buff == NULL)
	{
		perror("Error");
		exit(1);
	}
	/*Get the input*/
	x = getline(&buff, &n, stdin);

	if (x == -1)
	{
		free(buff);
		return (NULL);
	}
	else if (x > 1)
	{
		for (; i < x - 1; i++)
		{
			if (buff[i] == ' ')
				bksp++;
			else if (buff[i] != ' ' && buff[i] != '\n' && buff[i] != '\t')
				break;

			if (bksp == (x - 1))
			{
				free(buff);
				return (get_input());
			}
		}
	}

	/*return the input*/
	return (buff);
}

#include "shell.h"

/**
 * get_input - function to get input and put it into array
 *
 * Return: Array of argument
*/

char *get_input()
{
	char *buff;
	size_t n = BUFF_SIZE, x;

	buff = malloc(sizeof(char) * n);
	if (buff == NULL)
	{
		perror("Error\n");
		exit(1);
	}
	/*Get the input*/
	x = getline(&buff, &n, stdin);
	/*To Delete The newline*/
	buff[strlen(buff) - 1] = '\0';
	if (buff[0] == EOF)
		printf("Exit");
	if (x <= 0)
		return (NULL);

	/*return the input*/
	return (buff);
}

#include "shell.h"

/**
 * parse_input - function that parse the input and make it an array
 *
 * @buff: The commend line that (input)
 *
 * Return: The array of array
*/

char **parse_input(char *buff)
{
	char **arguments;
	char *token;
	int count = 0, num = 0;
	char *temp;

	if (!buff)
		return (NULL);
	/*To know the number of argument*/
	temp = _strdup(buff);
	token = strtok(temp, DELIMETER);
	if (token == NULL)
	{
		free(buff);
		free(temp);
		return (NULL);
	}
	while (token != NULL)
	{
		count++;
		token = strtok(NULL, DELIMETER);
	}
	/*To Make The input array of arguments*/
	arguments = malloc(sizeof(char *) * (count + 1));
	if (arguments == NULL)
	{
		free(temp);
		free(buff);
		return (NULL);
	}
	token = strtok(buff, DELIMETER);
	while (token != NULL)
	{
		arguments[num] = _strdup(token);
		token = strtok(NULL, DELIMETER);
		num++;
	}
	arguments[num] = NULL;
	free(buff);
	free(temp);
	return (arguments);
}

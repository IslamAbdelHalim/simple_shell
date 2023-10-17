#include "shell.h"

/**
 * freeArrStr - function to free Array of string
 *
 * @str: Array of string
*/

void freeArrStr(char **str)
{
	int i;

	if (str == NULL)
		return;

	for (i = 0; str[i]; i++)
		free(str[i]);
	free(str);
}


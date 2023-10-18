#include "shell.h"

/**
 * getTheEnv - Function that get the environment variable
 *
 * @varName: The Name of variable
 *
 * Return: pointer The Variable value or NULL if no variable
*/

char *getTheEnv(char *varName)
{
	int i;
	char *name, *varValue, *theVariable;

	for (i = 0; environ[i]; i++)
	{
		theVariable = environ[i];
		/*get the variable name*/
		name = strtok(theVariable, "=");
		/*compare the variable name with parameter*/
		if (_strcmp(name, varName) == 0)
		{
			varValue = strtok(NULL, "\n");
			return (varValue);
		}
	}
	return (NULL);
}

/**
 * getThePath - function that get the dirctory
 *
 * @cmd: The commend
 *
 * Return: pointer to correct directory or correct path of commend
*/

char *getThePath(char *cmd)
{
	char *directory, *commend, *check;
	int lendir, lencmd, i;
	struct stat st;

	for (i = 0; cmd[i]; i++)
	{
		if (cmd[i] == '/')
		{
			if (stat(cmd, &st) == 0)
				return (_strdup(cmd));
			return (NULL);
		}
	}
	check = getTheEnv("PATH");
	if (check == NULL)
		return (NULL);
	directory = strtok(check, ":");
	while (directory != NULL)
	{
		lendir = _strlen(directory);
		lencmd = _strlen(cmd);
		commend = malloc(lendir + lencmd + 2);
		if (commend == NULL)
		{
			free(directory);
			return (NULL);
		}
		_strcpy(commend, directory);
		_strcat(commend, "/");
		_strcat(commend, cmd);
		if (stat(commend, &st) == 0)
		{
			return (commend);
		}
		free(commend);
		directory = strtok(NULL, ":");
	}
	free(directory);
	return (NULL);
}

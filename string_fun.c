#include "shell.h"

/**
 * _strlen - function to Know the length of string
 *
 * @str: The string
 *
 * Return: The length of string
*/

int _strlen(char *str)
{
	int len = 0;

	if (!str)
		return (0);

	while (str[len] != '\0')
		len++;

	return (len);
}

/**
 * _strdup - function that duplicat the string
 *
 * @str: The string while duplicat
 *
 * Return: The pointer the new string
*/

char *_strdup(char *str)
{
	char *nstr;
	int size, i = 0;

	size = _strlen(str);
	nstr = malloc(sizeof(*str) * size + 1);
	if (nstr == NULL)
	{
		perror("Error");
		exit(1);
	}
	for (; i < size; i++)
		nstr[i] = str[i];
	nstr[i] = '\0';
	return (nstr);
}

/**
 * _strcmp - function to compare two string
 *
 * @str1: The First String
 *
 * @str2: The second string
 *
 * Return: The number of letter difference and 0 if no difference
*/

int _strcmp(char *str1, char *str2)
{
	int comp = 0;

	while (*str1)
	{
		if (*str1 != *str2)
		{
			comp = ((int)*str1 - 48) - ((int)*str2 - 48);
			break;
		}
		str1++;
		str2++;
	}
	return (comp);
}

/**
 * _strcat - function that concat two string
 *
 * @str1: The first string
 *
 * @str2: The string which will add
 *
 * Return: The pointer to new string
*/

char *_strcat(char *str1, char *str2)
{
	int i, j;

	i = 0;

	while (str1[i])
		i++;
	for (j = 0; str2[j]; j++)
	{
		str1[i++] = str2[j];
	}
	str1[i] = '\0';
	return (str1);
}

/**
 * _strcpy - function to copy string
 *
 * @str1: The string to copy to
 *
 * @str2: The string which copy
 *
 * Return: The poiner to the new string
*/

char *_strcpy(char *str1, char *str2)
{
	while (*str2 != '\0')
	{
		*str1 = *str2;
		str1++;
		str2++;
	}
	*str1 = '\0';
	return (str1);
}

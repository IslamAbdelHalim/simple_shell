#include "shell.h"

/**
 * _itoa - function that convert the num into ascii
 *
 * @num: the string
 *
 * Return: The integer
*/

char *_itoa(int num)
{
	char buff[20];
	int i = 0;

	if (num == 0)
		buff[i++] = '0';
	else
	{
		while (num > 0)
		{
			buff[i++] = (num % 10) + '0';
			num /= 10;
		}
	}

	buff[i] = '\0';
	rev_string(buff, i);
	return (_strdup(buff));
}

/**
 * rev_string - function reverse string
 *
 * @str: the string
 *
 * @len: the length
*/

void rev_string(char *str, int len)
{
	char temp;
	int i = 0;
	int e = len - 1;

	while (i < e)
	{
		temp = str[i];
		str[i] = str[e];
		str[e] = temp;
		i++;
		e--;
	}
}

/**
 * _error - function that print error
 *
 * @program: the shell name
 *
 * @commend: The name of commend
 *
 * @index: the index
*/
void _error(char *program, char *commend, int index)
{
	char *num;

	num = _itoa(index);
	
	write(1, program, _strlen(program));
	write(1, ": ", 2);
	write(1, num, _strlen(num));
	write(1, ": ", 2);
	write(1, commend, _strlen(commend));
	write(1, ": not found", 11);

	free(num);
}

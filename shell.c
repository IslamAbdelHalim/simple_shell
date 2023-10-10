#include "shell.h"

int main()
{
	char *buff = "#Simple_Shell$ ";
	while (1)
	{
		write(STDOUT_FILENO, buff, 15);
		printf("write done");
		get_input();
	}
	return (0);
}

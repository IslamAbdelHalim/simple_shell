#include "shell.h"

int main()
{
	int w;
	char *buff = "#Simple_Shell$ ";

	while (1)
	{
		w = write(STDOUT_FILENO, buff, 15);
		if (w == -1)
			return (1);
		get_input();
	}
	return (0);
}

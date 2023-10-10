#include "shell.h"

int main()
{
	int w;
	char *buff;

	while (1)
	{
		w = write(STDOUT_FILENO, "#Simple_Shell$ ", 15);
		if (w == -1)
			return (1);
		buff = get_input();
		exec(buff);
	}
	return (0);
}

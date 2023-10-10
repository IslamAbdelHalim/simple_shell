#include "shell.h"

int get_input()
{
	char *buff;
	size_t n;
	int bytes;
	printf("in function");
	buff = (char *)malloc(sizeof(char));
	printf("malloc done");
	n = 1;
	printf("size n done");
	bytes = getline(&buff, &n, 0);
	printf("getline done");
	return (bytes);
}

#include "shell.h"



int bridge(char *check, char **args)
{
	int i = 0;

	if (builtins_checker(args) == 1)
		return (1);
	while (check[i] != '\0')
	{
		if (check[i] == '/')
			return (1);
		i++;
	}
	return (2);
}

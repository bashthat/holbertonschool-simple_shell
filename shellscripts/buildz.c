#include "main.h"

/**
 * _cd - built in command to change directory.
 *
 * @args: list of arguments, 0 is "cd", 1 is the directory.
 * Return: always returns 1, to continue to execute.
 */
int _cd(char **args)
{
	char buffer[PATH_MAX];

	if (args[1] == NULL)
		fprintf(stderr, "$: expected argument to \"cd\"\n");
	else
	{
		if (chdir(args[1]) == 0)
		{
			printf("\nDirectory changed! Now in:\n");
			if (getcwd(buffer, PATH_MAX) == NULL)
				perror("unable to print directory path");
			else
				printf("%s\n", buffer);
		}
		else
			perror("chdir failed");
	}
	return (1);
}

/**
 * _help - built in command to change directory.
 *
 * Return: always returns 1, to continue to execute.
 */
int _help(void)
{
	int i, n;

	builtin_t builtins[] = {
		{"cd", _cd},
		{"help", _help},
		{"exit", my_exit},
		{"env", _env},
		{"history", _history},
	};

	n = N_BUILTINS(builtins, builtins[0]);
	printf("Available built-in commands:\n");
	for (i = 0; i < n; i++)
	{
		printf(" %s\n", builtins[i].name);
	}

	return (1);
}

/**
 * my_exit - built in command to exit shell.
 *
 * Return: always returns 0, to exit shell.
 */
int my_exit(void)
{
	return (0);
}

/**
 * _execute - looks for built ins or launches program.
 *
 * @args: list of arguments
 * @envp: enviroment pointer?
 * Return: returns 1 to continue running, 0 if exit.
 */
int _execute(char **args, char **envp)
{
	int i, n;

	builtin_t builtins[] = {
		{"cd", _cd},
		{"help", _help},
		{"exit", my_exit},
		{"env", _env},
		{"history", _history},
	};

	if (args[0] == NULL)
		return (1);

	n = N_BUILTINS(builtins, builtins[0]);
	for (i = 0; i < n; i++)
	{
		if (strcmp(args[0], builtins[i].name) == 0)
			return (builtins[i].f(args));
	}
	return (_launch(args, envp));
}

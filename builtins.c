#include "shell.h"

/**
 * *exit_shell - This runs the exit builtin
 * @line: Line buffer of user input
 * @args: users arguments
 * @env: Environment
 */

void exit_shell(char **args, char *line, char **env)
{
	free(args);
	free(line);
	(void)env;
	exit(0);
}

/**
 * env_shell - Prints a shell environment
 * @args: Arguments split from cmd line
 * @line: user input buffer
 * @env: environment
 */

void env_shell(char *args, char *line, char **env)
{
	int size, i = 0;

	while (env[i] != NULL)
	{
		size = _strlen(env[i]);
		write(1, env[i], size);
		write(1, "\n", 1);
		i++;
	}
	(void)args;
	(void)line;
}

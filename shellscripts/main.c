#include "main.h"

/**
 * main - shell for taking user commands
 *
 * @argc: argument count.
 * @argv: the arguments.
 * @envp: envroment pointer?
 * Return: int 0, upon exit.
 */

int main(int argc, char **argv, char **envp)
{
	char **line;
	char **args;
	int status;
	(void) argc, (void) argv;

	do {
		printf("$ ");
		line = read_line();
		args = split_line(*line);
		status = _execute(args, envp);

		free(*line);
		free(args);

	} while (status);
	return (0);
}

#include "main.h"

/**
 * _run - program.
 * @args: args.
 * Return: returns 1.
 */
int _run(char **args)
{
	int status;
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
			perror("execvp failed");
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
		perror(">$ ");
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}

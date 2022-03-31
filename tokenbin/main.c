#include "shell.h"

/**
 * main - entry point for shell
 * @ac: argument count
 * @av: array of arguments
 * @env: environment
 * Return: Always 0
 */

int main(int ac, char **av, char **env)
{
	if (!ac)
		(void)ac;
	if (!av)
		(void)av;
	if (!env)
		(void)env;
	shell(ac, av, env);
	return (0);
}

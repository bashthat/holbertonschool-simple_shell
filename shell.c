#include "shell.h"

/**
 * shell - infinite loop that runs the shell
 * @ac: Arg count
 * @av: args passed to shell at begining of prog
 * @env: environment
 * Return: void
 */

void shell(int ac, char **av, char **env)
{

	char *tmp = NULL;
	char *line;
	char **args;
	char *er;
	char *filename;
	int flow;
	int status = 1;

	er = "error";
	do {
		prompt();
		printf("here i am\n");
		line = _getline();
		args = split_line(line);
		flow = bridge(args[0], args);
		if (flow == 2)

		{
			filename = args[0];
			args[0] = find_path(args[0], tmp, er);
			if (args[0] == er)
			{
				args[0] = search_cwd(filename, er);
				if (args[0] == filename)
					write(1, er, 5);
			}
		}
		if (args[0] != er)
			status = execute_prog(args, line, env, flow);

	free(line);
	free(args);

	}
	while (status);
	if (!ac)
		(void)ac;
	if (!av)
		(void)av;
	if (!env)
		(void)env;
}

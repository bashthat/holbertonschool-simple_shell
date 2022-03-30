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
<<<<<<< HEAD
	static int first_time = 1;
	if ( first_time ) {
		const char* CLEAR_SCREEN_ANSI = "\e [1;1H\e[2J";
		write(STDOUT_FILENO, CLEAR_SCREEN_ANSI,12);
		first_time = 0;
	}
	printf("#");	
}
=======
	char *tmp = NULL;
	char *line;
	char **args;
	char *er;
	char filename;
	int flow;
	int status = 1;
>>>>>>> f23d76943637ffa20a71d8fd5d203298cc869680

	er = "ERROR";
	do {
		prompt();
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

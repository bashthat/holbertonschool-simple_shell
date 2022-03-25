#include <stdio.h> //printf
#include <string.h> //strlen
#include <stdlib.h> //exit
#include <unistd.h> //syscalls

/**
 * steps to coding the shell
 * ========================
 * first shoow prompt and read input.
 * ================================
 * second call parse command line (READ COMMAND LINE) and write code for parse.
 * command struct maxargs in struct. the struct command struct.
 * ========================================================
 * thrid parse(); and write the function out line -> struct.
 * =========================================================
 * fourth --> SYSTEM CALLS -- execution run command, run shell.
 * int main (9int argc, char const *argv[]); 
 * executing command == char* argv2[] = {"ls", "-la", NULL};
 * ========================================================
 * fifth --> Fork+Children -> childPid = fork() -- Pid = forking process. 
 * int main() 
 * pid_t childPid; -- parentPid + 1 = childPid
 * getpid()
 * =========
 * Fork + execvp = shell; 
 *======================
 * runsystemCommand(struct command *cmd, int bg);
 * ===========================
 * The files needed for the project in general given this process of coding a shell
 * prompt.c
 * parse.c
 * execsh.c
 * fork.c
 * shell.c
 *
 */


int MAXLINE = 1024;
char prompt[] = "lnsh>"; //commandline

int main(int argc, char **argv) {
	char cmdline[MAXLINE]; //buffer fgets

	while (1) {
	
		printf("%s", prompt);

		if ((fgets(cmdline, MAXLINE, stdin) == NULL) && ferror(stdin))
			error("fgets error");

		if (fgets(stdin)) {
			printf("\n");
			exit(0);
		}

		//remove trailing newline
		cmdline[strlen(cmdline)-1] = '\0';

		eval(cmdline);
	}
}

void eval(char *cmdline) {
	int bg;
	struct command cmd;

	printf("Evaluating '%s'\n", cmdline);

	//parse cmdline into cmd struct
	
	bg = parse(cmdline, &cmd);
	printf("Found Command %s\n", cmd.argv[0]);

	// -1 parse error
	if (bg == -1) return;
}

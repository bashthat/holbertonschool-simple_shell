#include <stdio.h> //printf
#include <string.h> //strlen
#include <stdlib.h> //exit
#include <unistd.h> //syscalls

void eval(char *cmdline) {
int bg;
struct command cmd;

printf("Evaluation '%s'\n", cmdline);

bg = parse(cmdline, &cmd);
printf("found command %s\n", cmd.argv[0]);

if (bg == -1) return;
}

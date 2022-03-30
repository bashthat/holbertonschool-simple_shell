#ifndef SHELL_H
#define SHELL_H


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <stddef.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

#define TOKENS_BUFFER_SIZE 64
#define LINE_SIZE 1024
#define TOKEN_DELIMITERS " \t\r\n\a"

<<<<<<< HEAD
node 
=======
extern char **environ;
>>>>>>> f23d76943637ffa20a71d8fd5d203298cc869680

/**
 * struct builtins - Has builtins and associated funcs
 * @arg: Builtins name
 * @builtin: Mathcing builtin func
 * **/

typedef struct builtins
{
	char *arg;
	void (*builtin)(char **args, char *line, char **env);
} builtins_t;

void shell(int ac, char **av, char **env);
void prompt(void);
char *_getline(void);
char **split_line(char *line);
int execute_prog(char **args, char *line, char **env, int flow);
int bridge(char *check, char **args);
int builtins_checker(char **args);
char *save_path(char *tmp, char *path);
void exit_shell(char **args, char *line, char **env);
void env_shell(char **args, char *line, char **env);
int _strcmp(char *s1, char *s2);
char *find_path(char *args, char *tmp, char *er);
char *search_cwd(char *filename, char *er);
char *_getenv(char *env);
char *_strstr(char *haystack, char *needle);
int launch_prog(char **args);
int check_for_builtins(char **args, char *line, char **env);
int _strlen(char *s);
char *save_path(char *tmp, char *path);
char *read_d(char *er, struct dirent *s, char *fil, int l, char *fp, char *t);
char *find_path(char *filename, char *tmp, char *er);

#endif

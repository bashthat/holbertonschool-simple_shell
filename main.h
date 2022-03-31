#ifndef SHELL_H
#define SHELL_H

#define N_BUILTINS(x, y) (sizeof(x) / sizeof(y))

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#include <linux/limits.h>
#include <sys/types.h>
#include <sys/stat.h>


/**
 * struct builtin_t - stores pointers to builtin functions
 * @name: name of builtin.
 * @f: function pointer to builtin.
 */
typedef struct builtin_s
{
	char *name;
	int (*f)();
} builtin_t;

/**
 * struct memaddr_t = list to remember pointers that need to be freed.
 * @name: name data
 * @prev: pointer to previous location.
 * @next: pointer to next location.
 */
typedef struct memaddr_s
{
	char *name;
	struct memaddr_s *prev;
	struct memaddr_s *next;
} memaddr_t;

extern char **environ;

int give_up(void);
int write_history(char *text_content);
int _cd(char **args);
int _help(void);
int my_exit(void);
int _env(void);
int _history(void);
int _launch(char **args, char **envp);
int _execute(char **args, char **envp);
char **read_line(void);
ssize_t _getline(char **lineptr, size_t *n);
char **split_line(char *line);
char *findfile(char **path, char *args);

/* path */
void _freemem(char **dirs);
char **arr_alloc(int n);
char **parsepath(char *p);
char **getpath(void);

/* strings */
char *_strchr(char *s, char c);
char *_strstr(char *s, char *substr);
char *_strndup(char *s, int n);
char *_strcat(char *dest, char *src);
int _strlen(char *s);

/* morestrings */
char *_strcpy(char *dest, char *src);
char *_memset(char *s, char b, unsigned int n);
void _memcpy(char *dest, char *src, size_t n);
void *_realloc(char *ptr, size_t size);

#endif

#include "hsh.h"

/**
 * main - main function for the shell
 * @argc: number of arguments
 * @argv: array of arguments
 * @env: environment variables
 * Return: 0 on success
 */

int main(void)
{
for (;;)
{
char *argv[2];
argv [0] = "/bin/sh";
argv [1] = NULL;
execvp(argv[0], argv);
}
}
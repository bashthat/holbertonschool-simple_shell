#include "main.h"

#define DELIM " \t\r\n\a"

/**
 * split_line - splits the line in segments.
 * Description:
 *
 * @line: sentence to be split.
 * Return: returns an array of segments.
 */
char **split_line(char *line)
{
	int bufsize, position;
	char **tokens, **tokens_backup, *token;

	bufsize = 64;
	position = 0;
	tokens = malloc(bufsize * sizeof(char *));

	if (!tokens)
	{
		fprintf(stderr, "$: allocation error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, DELIM);
	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		if (position >= bufsize)
		{
			bufsize = bufsize + 64;
			tokens_backup = malloc(bufsize * sizeof(char *));
			tokens_backup = tokens;
			free(tokens);
			tokens = malloc(bufsize * sizeof(char *));
			tokens = tokens_backup;
			if (!tokens)
			{
				free(tokens_backup);
				fprintf(stderr, "$: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, DELIM);
	}
	tokens[position] = NULL;
	return (tokens);
}

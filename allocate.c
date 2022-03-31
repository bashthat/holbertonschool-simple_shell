#include "main.h"

#define INIT_SIZE 120
#define MAX_SIZE 1024

/**
 * read_line - gets input from stdin.
 * Description: temp replacment for getline(). if buffer is filled, reallocate
 * more memory to buffer. also logs to history file.
 *
 * Return: returns the line it read from stdin.
 */
char **read_line(void)
{
	char **lineptr;
	size_t *n;

	n = malloc(sizeof(size_t));
	if (!n)
	{
		free(n);
		exit(EXIT_FAILURE);
	}
	*n = INIT_SIZE;

	lineptr = malloc(sizeof(char *));
	if (lineptr == NULL)
		exit(EXIT_FAILURE);

	*lineptr = (char *)malloc(*n);
	if (*lineptr == NULL)
	{
		free(*lineptr);
		exit(EXIT_FAILURE);
	}

	if (_getline(lineptr, n) < 0)
	{
		exit(EXIT_FAILURE);
	}
	return (lineptr);
}

/**
 *
 *
 *
 */
ssize_t _getline(char **lineptr, size_t *n)
{
	size_t new_len;
	char c, *curr, *new_lineptr;

	curr = *lineptr;
	while (1)
	{
		c = getchar();
		if (c == EOF)
		{
			if (curr == *lineptr)
				return (-1);
			break;
		}

		if ((*lineptr + *n - curr) < 2)
		{
			if (MAX_SIZE / 2 < *n)
				return (-1);
			new_len = *n * 2;
			new_lineptr = _realloc(*lineptr, new_len);
			if (!new_lineptr)
				return (-1);
			*lineptr = new_lineptr;
			*n = new_len;
		}

		*curr++ = c;
		if (c == '\n')
			break;
	}
	*curr = '\0';
	return ((ssize_t)(curr - *lineptr));
}

#include "main.h"

/**
 * _strcpy - copies a string to a buffer.
 * @dest: buffer.
 * @src: string to copy.
 * Return: char pointer to dest.
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}


/**
 * _memset - fills memory area with a constant byte.
 * @s: memory area.
 * @b: constant byte.
 * @n: number of bytes to fill.
 * Return: char pointer to memory srea s.
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i = 0;

	while (i < n)
	{
		*s = b;
		s++;
		i++;
	}
	return (s - i);
}

/**
 * _memcpy - copies
 * @dest: destination
 * @src: source for destination
 * @n: n
 */
void _memcpy(char *dest, char *src, size_t n)
{
	size_t i;

	for (i = 0; i < n; ++i)
	{
		if (&dest[i] == &src[i])
			exit(EXIT_FAILURE);
		dest[i] = src[i];
	}
}


/**
 * _realloc - realoc
 * @ptr: pointer
 * @size: size
 * Return: ptr
 */
void *_realloc(char *ptr, size_t size)
{
	void *tmp;

	tmp = ptr;
	ptr = malloc(sizeof(char) * size);
	_memcpy(ptr, tmp, size);
	free(tmp);
	return (ptr);
}

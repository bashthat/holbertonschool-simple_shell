#include "main.h"

/**
 * _strchr - locates a character in a string.
 * @s: string to search.
 * @c: character to search for.
 * Return: pointer to first occurence of c.
 * Or NULL, if c is not found.
 */
char *_strchr(char *s, char c)
{
	while (*s++ || *s == c)
	{
		if (*s == c)
			return (s);
	}
	return (NULL);
}

/**
 * _strstr - locates a substring.
 * @haystack: string to search.
 * @needle: substring to search for.
 * Return: pointer to beginning of located string,
 * or NULL, if substring is not found.
 */
char *_strstr(char *haystack, char *needle)
{
	int i;

	while (*haystack)
	{
		i = 0;
		while (*(haystack + i) == *(needle + i))
		{
			i++;
		}
		if (*(needle + i) == '\0')
		{
			return (haystack);
		}
		haystack++;
	}
	return (NULL);
}

/**
 * _strndup - allocates memory and duplicates n bytes of string.
 * @str: string to duplicate.
 * @n: bytes to duplicate.
 * Return: pointer to new string address.
 * Or NULL, on error.
 */
char *_strndup(char *str, int n)
{
	char *a;
	int i;

	if (!str)
		return (NULL);

	a = malloc(sizeof(char) * (n + 1));
	if (!a)
		return (NULL);

	for (i = 0; i < n && str[i]; i++)
	{
		a[i] = str[i];
	}
	a[i] = '\0';
	return (a);
}

/**
 * _strcat - concatenate two strings.
 * @dest: string input.
 * @src: string to concatenate to dest.
 * Return: char pointer to resulting string dest.
 */
char *_strcat(char *dest, char *src)
{
	char *s;

	s = dest;
	while (*dest != '\0')
		dest++;

	while (*src != '\0')
		*dest++ = *src++;

	*dest = '\0';
	return (s);

}

/**
 * _strlen - find string length.
 * @s: string.
 * Return: int, length in bytes.
 */
int _strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

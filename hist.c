#include "main.h"

/**
 * _history - prints command history.
 * Description: prints simple_shell_history file.
 *
 * Return: always returns 1, for shell to continue to function.
 */
int _history(void)
{
	FILE *fp;
	int c;

	fp = fopen("/tmp/.simple_shell_history", "r");
	while (1)
	{
		c = fgetc(fp);
		if (feof(fp))
		{
			break;
		}
		printf("%c", c);
	}
	fclose(fp);
	return (1);
}

/**
 * write_history - writes.
 *
 * @text_content: text to be written.
 * Return: 1 on success, -1 on failure.
 **/
int write_history(char *text_content)
{
	int temp, count;
	FILE *fp;

	if (text_content == NULL)
		return (-1);

	fp = fopen("/tmp/.simple_shell_history", "a");
	if (fp == NULL)
		return (-1);

	count = 0;
	while (text_content[count] != '\0')
	{
		count++;
	}

	temp = fwrite(text_content, 1, count, fp);
	fclose(fp);
	if (temp == -1)
		return (-1);

	return (1);
}

#include "main.h"
/**
 * format_err - fomrats error message
 * @av: argv[]
 * @input: input cmd
 * @count: shell command count
 * Return: format
 */

char *format_err(char **av, char *input, int count)
{
	char str_count[100], *format = NULL;
	int len;

	sprintf(str_count, "%d", count);
	len = strlen(av[0]) + strlen(input) + strlen(str_count) + 1;

	format = malloc(len + 7);
	if (format == NULL)
	{
		return (NULL);
	}

	strcpy(format, av[0]);

	strcat(format, ": ");
	strcat(format, str_count);
	strcat(format, ": ");
	strcat(format, input);

	return (format);
}

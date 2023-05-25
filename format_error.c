#include "main.h"
/**
 * format_err - formats error message
 * @av: argv[]
 * @input: input cmd
 * @count: shell command count
 * @err_msg: error message
 * Return: format
 */

char *format_err(char **av, char *input, int count, char *err_msg)
{
	char str_count[100], *format = NULL;
	int len;

	sprintf(str_count, "%d", count);
	len = strlen(av[0]) + strlen(input) + strlen(str_count) + strlen(err_msg) + 1;

	format = malloc(len + 9);
	if (format == NULL)
	{
		return (NULL);
	}

	strcpy(format, av[0]);

	strcat(format, ": ");
	strcat(format, str_count);
	strcat(format, ": ");
	strcat(format, input);
	strcat(format, ": ");
	strcat(format, err_msg);

	return (format);
}

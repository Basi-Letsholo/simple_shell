#include "main.h"

/**
 * _putchar - prints to stdout
 * @c: char to print
 * Return: 1 on succes
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _print - prints str using _putchar
 * @input: str to print
 * Return: 0 on success
 */
int _print(char *input)
{
	int i;

	for (i = 0; input[i] != '\0'; i++)
	{
		_putchar(input[i]);
	}
	_putchar('\n');
	return (0);
}

/**
 * rem_extraspace - removes extraspace in commandline
 * @input: user input
 * Return: input w/o extra space
 */
char *rem_extraspace(char *input)
{
	int i, j = 0, len, count = 0, front = 1;

	len = strlen(input);

	while (input[j] == ' ')
	{
		j++;
	}
	if (j == len)
	{
		input[0] = ' ';
		input[1] = '\0';
		return (input);
	}
	for (i = j; i < len; i++)
	{
		if (input[i] != ' ')
		{
			input[j] = input[i];
			j++;
			count = 0;
			front = 0;
		}
		else
		{
			if (count == 0 && front == 0)
			{
				input[j] = input[i];
				j++;
			}
			count++;
		}
	}
	if (j > 0 && input[j - 1] == ' ')
	{
		j--;
	}
	input[j] = '\0';

	return (input);
}

/**
 * get_input - prints prompt if shell interactive & gets user input
 * @ac: no. of arguments
 * @av: list of arguments
 * Return: 1 on success
 */
char *get_input(int ac, char **av)
{
	unsigned int i;
	char prompt[] = "Shell$ ", *input = NULL;
	size_t l;
	ssize_t r;
	(void)ac;
	(void)av;

	if (isatty(STDIN_FILENO))
	{
		for (i = 0; prompt[i] != '\0'; i++)
		{
			_putchar(prompt[i]);
		}
	}

	r = getline(&input, &l, stdin);
	if (r == -1)
	{
		if (feof(stdin))
		{
			free(input);
			printf("exiting..., \n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror(av[0]);
			free(input);
			return (NULL);
		}
	}
	strtok(input, "\n");
	input = rem_extraspace(input);
	if (strcmp(input, "exit") == 0)
	{
		free(input);
		exit(EXIT_SUCCESS);
	}

	return (input);
}

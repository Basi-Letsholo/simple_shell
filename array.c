#include "main.h"
/**
 * token_count - counts no. of tokens
 * @input: user input
 * @delim: separator
 * Return: count
 */
int token_count(char *input, char *delim)
{
	int count = 0;
	char *token;

	token = strtok(input, delim);
	while (token != NULL)
	{
		count++;
		token = strtok(NULL, delim);
	}
	return (count);
}

/**
 * array - splits str to an array
 * @input: user input
 * @delim: str deliminator
 * Return: array
 */
char **array(char *input, char *delim)
{
	int token_size, i = 0;
	char *token, **arr = NULL;
	char *input_cpy;

	input_cpy = malloc(sizeof(char) * (strlen(input) + 1));
	if (input_cpy == NULL)
	{
		perror("error");
		return (NULL);
	}
	strcpy(input_cpy, input);
	token_size = token_count(input_cpy, delim);

	arr = malloc((token_size + 1) * sizeof(char *));
	if (arr == NULL)
	{
		perror("error");
		exit(0);
	}

	strcpy(input_cpy, input);
	token = strtok(input_cpy, delim);
	while (token != NULL)
	{
		arr[i] = strdup(token);
		i++;
		token = strtok(NULL, delim);
	}
	arr[token_size] = NULL;
	free(input_cpy);
	return (arr);
}

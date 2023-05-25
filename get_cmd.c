#include "main.h"
/**
 * get_cmd - formats user input
 * @input: user input
 * Return: pointer to args
 */

char *get_cmd(char *input)
{
	unsigned int i;
	char *path, **delim_arr, *file_path;
	char **path_arr = NULL, *delim_buff;
	struct stat st;

	delim_arr = array(input, " \n");
	path = getenv("PATH");
	if (path != NULL)
	{
		path_arr = array(path, ":");
		if (path_arr[0] != NULL)
		{
			for (i = 0; path_arr[i] != NULL; i++)
			{
				file_path = malloc(sizeof(char) * (strlen(path_arr[i])
							+ strlen(delim_arr[0]) + 2));
				if (file_path == NULL)
				{
					free(path);
					free_arr(path_arr);
					return (NULL); }
				strcpy(file_path, path_arr[i]);
				strcat(file_path, "/");
				strcat(file_path, delim_arr[0]);
				strcat(file_path, "\0");
				if (stat(file_path, &st) == 0) /*checks if command exists, if not exits */
				{
					free_arr(path_arr);
					free_arr(delim_arr);
					return (file_path); }
				free(file_path); }
			free_arr(path_arr); }
	}
	if (stat(delim_arr[0], &st) == 0) /*checks if command exists, if not exits */
	{
		delim_buff = strdup(delim_arr[0]);
		free_arr(delim_arr);
		return (delim_buff); }
	free_arr(delim_arr);
	return (NULL);
}

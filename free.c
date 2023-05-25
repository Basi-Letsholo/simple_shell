#include "main.h"
/**
 * free_arr - frees memory to array
 * @arr: array to free
 * Return: void
 */

void free_arr(char **arr)
{
	int index;

	for (index = 0; arr[index] != NULL; index++)
	{
		free(arr[index]);
	}
	free(arr);
}

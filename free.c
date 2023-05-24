#include "main.h"

void free_arr(char **arr)
{
	int index;

	for (index = 0; arr[index] != NULL; index++)
	{
		free(arr[index]);
	}
	free(arr);
}

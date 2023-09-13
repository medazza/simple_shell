#include "shell.h"

/**
 * free_array - it's free array of strs.
 * @array: array of strs.
 * Return: void.
 */

void free_array(char **array)
{
	int index = 0;

	while (array[index] != NULL)
	{
		free(array[index]);
		index++;
	}
	free(array);
}

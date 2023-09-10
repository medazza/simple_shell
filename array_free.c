#include "shell.h"

/**
 * free_array - it's free array of strings
 * @array: array of strings
 * Return: void
 */

void free_array(char **array)
{
    int index = 0;

    while (array[index] != NULL) {
        free(array[index]);
        index++;
    }

    free(array);
}


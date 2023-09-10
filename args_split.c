#include "shell.h"

/**
 * tokenize - split a string into words
 * @buf: buf to store the input
 * Return: pointer to an array of strings
 */

char **tokenize(char *buf)
{
    char **words = NULL;
    unsigned int index = 0;

    words = malloc(sizeof(char *) * 1024);
    words[index] = _strtok(buf, " \t\n");
    while (words[index] != NULL)
    {
        words[++index] = _strtok(NULL, " \t\n");
    }
    words[index] = NULL;
    return (words);
}
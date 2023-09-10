#include "shell.h"

/**
 * make_path - makes a path
 * @path: path to make
 * @cmnd: command to add to path
 * Return: path
 */

char *make_path(char *path, char *cmnd)
{
	char *cmnd_path = NULL;

	cmnd_path = malloc(sizeof(char) * (_strlen(path) + _strlen(cmnd) + 2));
	if (cmnd_path == NULL)
		return (NULL);
	_strcpy(cmnd_path, path);
	_strcat(cmnd_path, "/");
	_strcat(cmnd_path, cmnd);
	return (cmnd_path);
}

/**
 * get_path - gets the path of a command
 * @cmnd: command to get the path of
 * Return: path of the command
 */

char *get_path(char *cmnd)
{
	char *path = NULL, *path_co = NULL, *token = NULL, *cmnd_path = NULL;
	struct stat st;

	if (stat(cmnd, &st) == 0)
		return (cmnd);
	if (cmnd == NULL)
		return (NULL);
	if (cmnd[0] == '/')
	{
		if (stat(cmnd, &st) == 0)
			return (cmnd);
		return (NULL);
	}
	path = _getenv("PATH");
	path_co = _strdup(path);
	token = strtok(path_co, ":");
	while (token != NULL)
	{
		cmnd_path = make_path(token, cmnd);
		if (stat(cmnd_path, &st) == 0)
		{
			free(path_co);
			return (cmnd_path);
		}
		free(cmnd_path);
		token = strtok(NULL, ":");
	}
	free(path_co);
	return (NULL);
}
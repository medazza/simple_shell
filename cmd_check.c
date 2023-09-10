#include "shell.h"

/**
 * check_cmd - checks if exits a command
 * @cmnd: command to check
 * Return: 1 exits, 0 if not
 */

int check_cmd(char *cmnd)
{
	char *envPath = NULL, *pathCop = NULL;
	char *pathToken = NULL, *cmnd_path = NULL;
	struct stat st;

	if (stat(cmnd, &st) == 0)
		return (1);
	if (cmnd == NULL)
		return (0);
	if (cmnd[0] == '/')
	{
		if (stat(cmnd, &st) == 0)
			return (1);
		return (0);
	}
	envPath = _getenv("PATH");
	if (envPath == NULL)
		return (0);
	pathCop = _strdup(envPath);
	if (pathCop == NULL)
		return (0);
	pathToken = strtok(pathCop, ":");
	while (pathToken != NULL)
	{
		cmnd_path = malloc(sizeof(char) * (_strlen(pathToken) + _strlen(cmnd) + 2));
		_strcpy(cmnd_path, pathToken);
		_strcat(cmnd_path, "/");
		_strcat(cmnd_path, cmnd);
		if (stat(cmnd_path, &st) == 0)
		{
			free(pathCop);
			free(cmnd_path);
			return (1);
		}
		free(cmnd_path);
		pathToken = strtok(NULL, ":");
	}
	free(pathCop);
	return (0);
}
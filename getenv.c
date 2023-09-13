#include "shell.h"

/**
 * _getenv - gets the env var
 * @key: key to get the value
 * Return: value of the environment var.
 */

char *_getenv(const char *key)
{
	unsigned int key_len = 0;
	unsigned int index1 = 0, index2 = 0;
	char *value = NULL;

	if (key == NULL)
		return (NULL);
	key_len = _strlen(key);
	while (environ[index1])
	{
		while (environ[index1][index2] == key[index2])
		{
			if (index2 == key_len - 1)
			{
				value = environ[index1] + key_len + 1;
				return (value);
			}
			index2++;
		}
		index1++;
		index2 = 0;
	}
	return (NULL);
}

/**
 * len_env - gets the length of the environment
 * @env: environment
 * Return: length of the environment
 */

int len_env(char **env)
{
	int i = 0;

	while (env[i])
		i++;
	return (i);
}

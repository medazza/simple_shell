#include "shell.h"

/**
 * handle_echo_args - handles the $ builtin cmnd
 * @args: array of str
 * @status: exit the status
 */
void handle_echo_args(char *args, int *status)
{
	char *res = NULL;
	(void)status;

	if (_strncmp(args, "$$", 2) == 0)
	{
		res = _itoa(getpid());
		write(STDOUT_FILENO, res, _strlen(res));
		write(STDOUT_FILENO, "\n", 1);
		free(res);
		return;
	}
	if (_strncmp(args, "$", 1) == 0)
	{
		res = _getenv(args + 1);
		if (res != NULL)
		{
			write(STDOUT_FILENO, res, _strlen(res));
			write(STDOUT_FILENO, "\n", 1);
			return;
		}
	}
	if (_strncmp(args, "$?", 2) == 0)
	{
		write(STDOUT_FILENO, _getenv("?"), _strlen(_getenv("?")));
		write(STDOUT_FILENO, "\n", 1);
		free(res);
		return;
	}
	if (args == NULL)
	{
		write(STDOUT_FILENO, "\n", 1);
		return;
	}
	write(STDOUT_FILENO, "\n", 1);
}

/**
 * handle_echo - handles the echo  with '"'.
 * @args: array of strs.
 * @status: exit the status.
 * Return: 1 if cmd is a builtin, 0 else.
 */

int handle_echo(char **args, int *status)
{
	int index = 1, flag = 0, j = 0;

	if (args == NULL)
	{
		write(STDOUT_FILENO, "\n", 1);
		return (1);
	}
	if (args[1] == NULL)
	{
		write(STDOUT_FILENO, "\n", 1);
		return (1);
	}
	if (_strncmp(args[0], "echo", 4) != 0)
		return (0);
	if (_strncmp(args[1], "$", 1) == 0 || _strncmp(args[1], "$$", 2) == 0 ||
			_strncmp(args[1], "$?", 2) == 0)
	{
		handle_echo_args(args[1], status);
		return (1);
	}
	for (index = 1; args[index] != NULL; index++)
	{
		for (j = 0; args[index][j] != '\0'; j++)
		{
			if (args[index][j] == '$')
			{
				flag = 1;
				handle_echo_args(args[index] + j, status);
				break;
			}
			if (args[index][j] != '"')
				write(STDOUT_FILENO, &args[index][j], 1);
		}
		if (args[index + 1] != NULL)
			write(STDOUT_FILENO, " ", 1);
	}
	if (flag == 0)
		write(STDOUT_FILENO, "\n", 1);
	return (1);
}

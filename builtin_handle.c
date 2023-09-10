#include "shell.h"

/**
 * print_env - prints the environment variables
 * @env: env var
 * Return: void
 */

void print_env(char **env)
{
	int i = 0;

	while (env[i] != NULL)
	{
		write(STDOUT_FILENO, env[i], _strlen(env[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}

/**
 * builtins - handles the builtins
 * @args: array of strings
 * @env: environment variables
 * Return: 1 command is a builtin, 0 else
 */

int builtins(char **args, char **env)
{
	if (handle_builtins1(args, env))
		return (1);
	if (handle_builtins3(args))
		return (1);
	if (handle_builtins2(args))
		return (1);
	return (0);
}

/**
 * handle_builtins1 - handles the builtins
 * @args: array of strs
 * @env: env var
 * Return: 1 command is a builtin, 0 else
 */

int handle_builtins1(char **args, char **env)
{
	int i = 0;

	if (_strncmp(args[0], "exit", 4) == 0)
		exit(EXIT_SUCCESS);
	if (_strncmp(args[0], "env", 3) == 0)
	{
		while (env[i] != NULL)
		{
			write(STDOUT_FILENO, env[i], _strlen(env[i]));
			write(STDOUT_FILENO, "\n", 1);
			i++;
		}
		return (1);
	}
	return (0);
}

/**
 * handle_builtins2 - handles the builtins
 * @args: array of strings
 * Return: 1 command is a builtin, 0 else
 */

int handle_builtins2(char **args)
{
	if (_strncmp(args[0], "setenv", 6) == 0)
	{
		if (args[1] == NULL)
		{
			write(STDERR_FILENO, "How: setenv [VARIABLE] [VALUE]\n", 31);
			return (1);
		}
		if (args[2] == NULL)
		{
			return (1);
		}
		return (1);
	}
	if (_strncmp(args[0], "unsetenv", 8) == 0)
	{
		if (args[1] == NULL)
		{
			write(STDERR_FILENO, "How: unsetenv [VARIABLE]\n", 25);
			return (1);
		}
		return (1);
	}
	return (0);
}

/**
 * handle_builtins3 - handles the builtins
 * @args: array of strings
 * Return: 1 command is a builtin, 0 else
 */

int handle_builtins3(char **args)
{
	if (_strncmp(args[0], "clear", 5) == 0)
	{
		write(STDOUT_FILENO, "\033[H\033[J", 6);
		return (1);
	}
	if (_strncmp(args[0], "echo", 4) == 0)
	{
		handle_echo(args, NULL);
		return (1);
	}
	if (_strncmp(args[0], "cd", 2) == 0)
	{
		my_cd(args);
		return (1);
	}
	return (0);
}
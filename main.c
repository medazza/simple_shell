#include "shell.h"

/**
 * execute - we did it for split main only
 * @cmnd: command to check.
 * @env: env var.
 * @argv: argument vector.
 * Return: void.
 */

void execute(char *cmnd, char **env, char **argv)
{
	char **args = tokenizez(cmnd, " \t\r\n\a");

	if (!check_cmd(args[0]))
	{
		write(STDOUT_FILENO, "Command not found: ", 19);
		write(STDOUT_FILENO, args[0], _strlen(args[0]));
		write(STDOUT_FILENO, "\n", 1);
	}
	else
		run_cmd(args, env, argv);
	free(args);
}

/**
 * main - main function entry of the shell
 * @argc: argument counter
 * @argv: argument vector
 * @env: environment variable
 * Return: 0 on successful
 */

int main(int argc, char **argv, char **env)
{
	char *buffer = NULL;
	size_t buffer_size = 0;
	int n_char = 0;
	bool shell = false;
	(void)argc;

	while (1 && !shell)
	{
		if (isatty(STDIN_FILENO) == 0)
			shell = true;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		n_char = _getline(&buffer, &buffer_size, STDIN_FILENO);
		if (n_char == -1 || (n_char == 0 && isatty(STDIN_FILENO)))
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			break;
		}
		if (buffer[n_char - 1] == '\n')
			buffer[n_char - 1] = '\0';
		if (buffer[0] == '\n' || empty_line(buffer))
			continue;
		if (strcmp(buffer, "exit") == 0)
		{
			free(buffer);
			buffer = NULL;
			break;
		}
		execute(buffer, env, argv);
	}
	free(buffer);
	return (0);
}

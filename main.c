#include "shell.h"

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
	int n_char = 0, ind;
	bool shell = false;
	(void)argc;

	while (1 && !shell)
	{
		if (isatty(STDIN_FILENO) == 0)
			shell = true;
		write(STDOUT_FILENO, "$ ", 2);
		n_char = _getline(&buffer, &buffer_size, STDIN_FILENO);
		if (n_char == EOF)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			break;
		}
		ind = 0;
		while (buffer[ind])
		{
			if (buffer[ind] == '\n')
				buffer[ind] = '\0';
			ind++;
		}
		if (buffer[0] == '\n')
			continue;
		handle_input(buffer, env, argv);
		buffer_size = 0;
		buffer = NULL;
	}
	return (0);
}

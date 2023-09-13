#include "shell.h"

/**
 * tokenizez - tokenizes a str using a del
 * @str_input: str to tokenize
 * @del: delimiter
 * Return: array of args
 */

char **tokenizez(char *str_input, char *del)
{
	char **args = NULL;
	char *token = NULL;
	int ind = 0, buffersize = 0;

	if (str_input == NULL)
		return (NULL);
	buffersize = _strlen(str_input);
	args = malloc(sizeof(char *) * buffersize);
	if (args == NULL)
		return (NULL);
	token = strtok(str_input, del);
	while (token != NULL)
	{
		args[ind] = token;
		token = strtok(NULL, del);
		ind++;
	}
	args[ind] = NULL;
	return (args);
}

/**
 * handle_input - handles the input from the user
 * @buffer: buffer to store the input
 * @env: env var
 * @argv: arguments vector
 * Return: 0 on success
 */

int handle_input(char *buffer, char **env, char **argv)
{
	char **args = NULL, **cmnd = NULL;
	int index = 0, bufsize = 0;

	bufsize = _strlen(buffer);
	cmnd = malloc(sizeof(char *) * bufsize);
	if (cmnd == NULL)
		return (-1);
	args = tokenizez(buffer, ";\n");
	while (args[index] != NULL)
	{
		cmnd = tokenizez(args[index], " \t\r\n\a");
		if (cmnd[0] != NULL)
			run_cmd(cmnd, env, argv);
		free(cmnd);
		index++;
	}
	free(args);
	return (0);
}

/**
 * sigint_handler - handles SIGINT
 * @sign: the signal to handle
 */

void sigint_handler(int sign)
{
	(void)sign;
	write(STDOUT_FILENO, "\n$ ", 3);
}

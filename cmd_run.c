#include "shell.h"

/**
 * run_cmd - runs a cmd.
 * @args: args
 * @argv: argument vector.
 * @env: env var
 * Return: 0 on successful, 1 on failure.
 */

int run_cmd(char **args, char **env, char **argv)
{
	char *path_cmnd = NULL;
	int status = 0;
	pid_t pid = 0;
	int cmnd_exits = 0;

	status = builtins(args, env);
	cmnd_exits = check_cmd(args[0]);
	if (status == 0 && cmnd_exits == 1)
	{
		path_cmnd = get_path(args[0]);
		pid = fork();
		if (pid == -1)
		{
			perror("Error");
			free_array(args);
			return (-1);
		}
		if (pid == 0)
		{
			if (execve(path_cmnd, args, NULL) == -1)
			{
				free_array(args);
				return (-1);
			}
		}
		else
			wait(NULL);
	}
	if (status == 0 && cmnd_exits == 0)
		perror(argv[0]);
	return (0);
}

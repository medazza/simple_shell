#include "shell.h"

/**
 * my_cd - changes the current working directory
 * @args: argums.
 */

void my_cd(char **args)
{
	char **dirs = NULL, *oldpwd = NULL, *home = NULL;

	if (args[1] == NULL)
	{
		home = _getenv("HOME");
		if (home == NULL)
		{
			write(STDERR_FILENO, "cd:HOME not set\n", 16);
			return;
		}
		dirs = malloc(sizeof(char *) * 2);
		if (dirs == NULL)
			return;
		dirs[0] = home;
		dirs[1] = NULL;
	}
	else if (_strncmp(args[1], "-", 1) == 0)
	{
		oldpwd = _getenv("OLDPWD");
		if (oldpwd == NULL)
		{
			write(STDERR_FILENO, "cd:OLDPWD not set\n", 18);
			return;
		}
		dirs = malloc(sizeof(char *) * 2);
		if (dirs == NULL)
			return;
		dirs[0] = oldpwd;
		dirs[1] = NULL;
	}
	else
	{
		dirs = malloc(sizeof(char *) * 2);
		if (dirs == NULL)
			return;
		dirs[0] = args[1];
		dirs[1] = NULL;
	}
	change_directory(dirs, args[0]);
	free(dirs);
}

/**
 * change_directory - changes the current working directory
 * @dirs: directories to change to
 * @cmnd_name: name of the command
 */

void change_directory(char **dirs, char *cmnd_name)
{
	char *pwd = getcwd(NULL, 0);

	if (chdir(dirs[0]) == -1)
	{
		print_err(cmnd_name, 0, dirs[0], "can't cd to ");
		return;
	}
	else
		free(pwd);
}

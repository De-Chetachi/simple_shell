#include "my_shell.h"
/**
* my_exit - exits my shell
* @argv: An array of strings passin in stdin
* Return: Void
*/

void my_exit(char **argv)
{
	int exit_stat = exit_status;

	if (argv[1])
	{
		if ((argv[1][0] < '0') || (argv[1][0] > '9'))
		{
			error_exit(STDERR_FILENO, av[0], argv);
			exit_stat = 2;
		}
		else
		{
			exit_stat = _atoi(argv[1]);
		}
	}
	free_double(argv);
	free_double(cmds);
	free(cmd_str);
	free_double(path_arr);
	exit(exit_stat);
}

/**
* my_env - prints the environment variables
* @argv: An array of strings passin in stdin
* Return: Void
*/

void my_env(char **argv)
{
	int i = 0;
	(void)argv;


	while (environ[i])
	{
		puts(environ[i]);
		i++;
	}
}

/**
* my_cd - changes my current working directory
* @argv: An array of strings passin in stdin
* Return: Void
*/

void my_cd(char **argv)
{
	char *home;
	char *olddir;
	char *dir;
	char *dir_buf = NULL;
	size_t dir_size = 0;
	int argc;
	char *temp_pwd;

	argc = arr_len(argv);
	temp_pwd = _getenv("PWD", environ);
	if (argc == 1)
	{
		home = _getenv("HOME", environ);
		chdir(home);
	}
	else if (argc > 1)
	{
		if (_strcmp(argv[1], "-") == 0)
		{
			olddir = _getenv("OLDPWD", environ);
			chdir(olddir);
		}
		else
		{
			if (chdir(argv[1]) != 0)
			{
				error_cd(STDERR_FILENO, av[0], argv);
			}
		}
	}
	dir = getcwd(dir_buf, dir_size);
	setenv("PWD", dir, 1);
	setenv("OLDPWD", temp_pwd, 1);
	free(dir_buf);
	free(dir);
}

/**
* my_setenv - sets a new environment variable or modifies already existing one
* @argv: An array of strings passin in stdin
* Return: Void
*/

void my_setenv(char **argv)
{
	int argc = arr_len(argv);

	if (argc != 3)
	{
		perror("invalid number of commands");
	}
	else
	{
		setenv(argv[1], argv[2], 1);
	}
}
/**
* my_unsetenv - unsets an existing env variable
* @argv: An array of strings passin in stdin
* Return: Void
*/

void my_unsetenv(char **argv)
{
	int argc = arr_len(argv);
	if (argc != 2)
	{
		perror("invalid number of commands");
	}
	else
	{
		unsetenv(argv[1]);
	}
}

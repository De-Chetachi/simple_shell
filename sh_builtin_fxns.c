#include "my_shell.h"
/**
* my_exit - exits my shell
* @argv: An array of strings passin in stdin
* Return: 0 or 1
*/

void my_exit(char **argv)
{
	int exit_status = 0;


	if (argv[1])
	{
		exit_status = atoi(argv[1]);
	}
	free_double(argv);
	exit(exit_status);
}

/**
* my_env - prints the environment variables
* @argv: An array of strings passin in stdin
* Return: 0 or 1
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
* Return: 0 or 1
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
	temp_pwd = getenv("PWD");
	if (argc == 1)
	{
		home = getenv("HOME");
		chdir(home);
	}
	else if (argc > 1)
	{
		if (strcmp(argv[1], "-") == 0)
		{
			olddir = getenv("OLDPWD");
			chdir(olddir);
		}
		else
		{
			if (chdir(argv[1]) != 0)
				perror(argv[1]);
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
* Return: 0 or 1
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
* Return: 0 or 1
*/

void my_unsetenv(char **argv)
{
	int argc = arr_len(argv);
	if (argc != 3)
	{
		perror("invalid number of commands");
	}
	else
	{
		unsetenv(argv[1]);
	}
}

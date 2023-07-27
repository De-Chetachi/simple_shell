#include "my_shell.h"

/**
* error_stat - prints the required error when stat fails
* @stream:  File descriptor where the eeror is to be printed
* @program: The first element of argv
* @cmd: The first element passed on the command line
* Return: nothing
*/

void error_stat(int stream, char *program, char *cmd)
{
	char *pg = program;
	char *cd = cmd;

	if (pg && cd)
	{
		while (*pg != '\0')
		{
			write(stream, pg, 1);
			pg++;
		}
		write(stream, ": 1: ", 5);
		while (*cd != '\0')
		{
			write(stream, cd, 1);
			cd++;
		}
		write(stream, ": not found\n", 12);

	}
}

/**
* error_cd - prints the required error when cd fails
* @stream:  File descriptor where the eeror is to be printed
* @program: The first element of argv
* @cmd: The elements passed on the command line
* Return: Void
*/

void error_cd(int stream, char *program, char **cmd)
{
	char *a = ": can't cd to ";
	int aa = strlen(a);
	char **cd = cmd;
	char *cd_a;
	char *cd_b;
	char *pg = program;

	if (pg && cd)
	{
		cd_a = cd[0];
		cd_b = cd[1];
		while (*pg != '\0')
		{
			write(stream, pg, 1);
			pg++;
		}
		write(stream, ": 1: ", 5);
		while (*cd_a != '\0')
		{
			write(stream, cd_a, 1);
			cd_a++;
		}
		write(stream, a, aa);
		while (*cd_b != '\0')
		{
			write(stream, cd_b, 1);
			cd_b++;
		}
		write(stream, "\n", 1);
	}
}

/**
* error_exit - prints the required error when exit fails
* @stream:  File descriptor where the eeror is to be printed
* @program: The first element of argv
* @cmd: The elements passed on the command line
* Return: Void
*/

void error_exit(int stream, char *program, char **cmd)
{
	char *a = ": Illegal number: ";
	char **cd = cmd;
	char *cd_a;
	char *cd_b;
	char *pg = program;
	int aa = strlen(a);

	if (pg && cd)
	{
		cd_a = cmd[0];
		cd_b = cmd[1];
		while (*pg != '\0')
		{
			write(stream, pg, 1);
			pg++;
		}
		write(stream, ": 1: ", 5);
		while (*cd_a != '\0')
		{
			write(stream, cd_a, 1);
			cd_a++;
		}
		write(stream, a, aa);
		while (*cd_b != '\0')
		{
			write(stream, cd_b, 1);
			cd_b++;
		}
		write(stream, "\n", 1);
	}
}

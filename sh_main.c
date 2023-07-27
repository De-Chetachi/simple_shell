#include "my_shell.h"
char *cmd_str = NULL;
char **cmds;
char **evi;
char *path;
int path_len;
char **path_arr;
int exit_status;
char **av;
int determinant;

/**
* c_handler - handles ctrl+c
* @signal: Signal recieved
* Return: Void
*/

void c_handler(int signal)
{
	(void)signal;
	free(cmd_str);
	free_double(path_arr);
	exit(EXIT_FAILURE);
}

/**
* main - entry point of our shell
* @ac: Number of command line args
* @ag: Command line arguments
* Return: 0 or 1
*/
int main(int ac, char **ag)
{
	av = ag;
	signal(SIGINT, c_handler);
	path = _getenv("PATH", environ);
	path_arr = tok_str(path, ":", &path_len);
	determinant = 1;

	(void)ac;
	if (isatty(STDIN_FILENO) == 1)
	{
		sh_interactive();
		if (determinant != 1)
			return (determinant);
	}
	else if (isatty(STDIN_FILENO) == 0) 
	{
		sh_uninteractive();
		if (determinant != 1)
			return (determinant);
	}
	return (0);
}

#include "my_shell.h"
/**
* c_handler - handles ctrl+c
* @signal: Signal recieved
* Return: Void
*/

void c_handler(int signal)
{
	(void)signal;
	fflush(stdin);
	free(cmd_str);
	free_double(path_arr);
	exit(EXIT_FAILURE);
}
void z_handler(int signal)
{
	(void)signal;
	free(cmd_str);
	free_double(path_arr);
	exit(EXIT_SUCCESS);
}

/**
* main - entry point of our shell
* Return: 0 or 1
*/
char *cmd_str;
char *path;
int path_len;
char **path_arr;

int main()
{
	signal(SIGINT, c_handler);
	path = getenv("PATH");
	path_arr = tok_str(path, ":", &path_len);

	if (isatty(STDIN_FILENO) == 1)
	{
		sh_interactive();
	}
	else if (isatty(STDIN_FILENO) == 0) 
	{
		sh_uninteractive();
	}

	return (0);
}

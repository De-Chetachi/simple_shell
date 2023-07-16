#include "my_shell.h"

/**
* sh_interactive - prints a prompt and executes a command in a loop
* Return: Void
*/

void sh_interactive(void)
{
	char *prompt = "$ ";
	char *cmd_str;
	char **cmd_arr;
	int i;
	int determinant = 1;
	int cmd_arr_len;

	/*loop*/
	while (determinant == 1)
	{
		/*print a prompt*/
		i = 0;
		while (prompt[i])
		{
			putchar(prompt[i]);
			i++;
		}

		/*read input*/
		cmd_str = read_line();

		/*tokenize the string*/
		cmd_arr = tok_str(cmd_str, " ", &cmd_arr_len);

		/*execute the command*/
		determinant = exe_cute(cmd_arr);

		free(cmd_str);
		free_double(cmd_arr);
		/*execute the command*/

	}
}

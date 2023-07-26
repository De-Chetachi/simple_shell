#include "my_shell.h"

/**
* sh_interactive - prints a prompt and executes a command in a loop
* Return: Void
*/

void sh_interactive(void)
{
	char *prompt = "$ ";
	char *cmd_line;
	char **cmd_arr;
	int cmd_num;
	int j;
	int cmd_arr_len;

	/*loop*/
	while (determinant >= 1)
	{
		/*print a prompt*/
		write(STDIN_FILENO, prompt, 2);

		/*read input*/
		cmd_str = read_line();

		cmd_line = tok_once(cmd_str, "#");

		cmds = tok_str(cmd_line, ";", &cmd_num);

		j = 0;
		while (j < (cmd_num - 1) && determinant >= 1)
		{
		/*tokenize the string*/
			cmd_arr = tok_str(cmds[j], " \n\t", &cmd_arr_len);
		/*execute the command*/
			 determinant = exe_cute(cmd_arr);
			 free_double(cmd_arr);
			 j++;
		}
		free(cmd_str);
		free_double(cmds);
		/*execute the command*/

	}
}

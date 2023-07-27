#include "my_shell.h"

/**
* sh_uninteractive - runs a piped  command
* Return: void
*/

void sh_uninteractive(void)
{
	char **cmd_arr;
	char *cmd_line;
	size_t cmd_len;
	int cmd_arr_len;
	ssize_t bytes;
	int cmd_num, j;
	
	/*read line from stdin*/
	while ((bytes = getline(&cmd_str, &cmd_len, stdin)) != -1)
	{
		cmd_line = tok_once(cmd_str, "#");

		cmds =  tok_str(cmd_line, ";", &cmd_num);

		j = 0;
		while (j < (cmd_num - 1) && determinant >= 1)
		{
			cmd_arr = tok_str(cmds[j], "\n\t ", &cmd_arr_len);

			determinant = exe_cute(cmd_arr);
			free_double(cmd_arr);
			j++;
		}
		free_double(cmds);
	}
	free(cmd_str);
	free_double(path_arr);
}

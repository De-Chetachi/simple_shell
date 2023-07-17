#include "my_shell.h"

/**
* sh_uninteractive - runs a piped  command
* Return: void
*/

void sh_uninteractive(void)
{
	char *cmd_str;
	char **cmd_arr;
	int cmd_arr_len;

	/*read line from stdin*/
	cmd_str = read_line();
	
	cmd_arr = tok_str(cmd_str, " ", &cmd_arr_len);
	
	exe_cute(cmd_arr);
	free(cmd_str);
	free(cmd_arr);
	free(path_arr);
}

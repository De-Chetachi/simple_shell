#include "my_shell.h"

/**
* sh_uninteractive - runs a piped  command
* Return: void
*/

void sh_uninteractive(void)
{
	char *cmd_str;

	/*read line from stdin*/
	cmd_str = read_line();
	puts(cmd_str);
}

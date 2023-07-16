#include "my_shell.h"

/**
* exe_cute - execute a given command
* @argv: An array of strings
* Return: 0 or 1
*/
int exe_cute(char **argv)
{
	/*handle empty commands*/
	if (argv[0] == NULL)
	{
		return (1);
	}

	/*handle built_ins*/
	if (handle_bt_ins(argv) == 1)
		 return (1);

	/*handle executable commands*/
	 if (handle_executable(argv) == 1)
		return (1);

	return (0);
}

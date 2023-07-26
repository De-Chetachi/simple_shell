#include "my_shell.h"

/**
* handle_bt_ins - handle some builtins command for our shell
* @argv: Our command array
* Return: 1 or 0;
*/

int handle_bt_ins(char **argv)
{
	char *builtin_strs[6];
	void (*builtin_fxns[6])(char **);
	int i, bltin_len;
	int res = 0;


	builtin_strs[0] = "cd";
	builtin_strs[1]	= "exit";
	builtin_strs[2]	= "env";
	builtin_strs[3]	= "setenv";
	builtin_strs[4] = "unsetenv";

	builtin_fxns[0] = &my_cd;
	builtin_fxns[1] = &my_exit;
	builtin_fxns[2] = &my_env;
	builtin_fxns[3]	= &my_setenv;
	builtin_fxns[4]	= &my_unsetenv;

	bltin_len = 5;

	i = 0;
	while (i < bltin_len)
	{
		if (_strcmp(argv[0], builtin_strs[i]) == 0)
		{
			builtin_fxns[i](argv);
			res = 1;
			break;
		}
		i++;
	}
	return (res);
}

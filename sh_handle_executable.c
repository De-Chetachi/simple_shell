#include "my_shell.h"

/**
* handle_executable - handles the execution of executable commands
* @argv: The command array
* Return: 1
*/

int handle_executable(char **argv)
{
	/**
	* check if file exists else handle path
	* if file exists create a new process
	* else print error
	* in the new process chech if the file is an executable
	* if it is execute it
	* else handle error 
	* return 1
	*/
	argv[0] = handle_path(argv[0]);
	if (argv[0] == NULL)
		return (1);

	if (access(argv[0], X_OK) == 0)
	{
		fork_exec(argv);
	}
	else
	{
		perror(argv[0]);
	}
	return (1);
}

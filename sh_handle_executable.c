#include "my_shell.h"

/**
* handle_executable - handles the execution of executable commands
* @argv: The command array
* Return: 1
*/

int handle_executable(char **argv)
{
	struct stat st;
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
	if (stat(argv[0], &st) != 0)
	{
		error_stat(STDERR_FILENO, av[0], argv[0]);
		return (127);
	}

	if (access(argv[0], X_OK) != 0)
	{
		perror(argv[0]);
		return (2);
	}
	else
	{
		fork_exec(argv);
	}
	return (1);
}

#include "my_shell.h"
/**
* fork_exec - This program creates a child process
* @argv: The array of command argument
*
* Return: The PID of the child process or -1 on failure
*/

pid_t fork_exec(char **argv)
{
	int status;
	char *cmd;
	pid_t child_pid;


	child_pid = fork();


	if (child_pid == -1)
	{
		perror("Error creating child process");
		return (-1);
	}


	if (child_pid == 0)
	{
		if (argv)
		{
			cmd = argv[0];
			if (execve(cmd, argv, environ) == -1)
			{
				perror("Error executing cmd");
				return (-1);
			}
		}
	}
	else
	{
		wait(&status);
	}


	return (child_pid);
}

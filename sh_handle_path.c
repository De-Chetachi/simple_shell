#include "my_shell.h"
/**
* path_append - apends the command to path
* @cmd: The command
* Return: Pointer to an array of strings
*/
char **path_append(char *cmd)
{
	int k, path_size, cmd_len;
	char **cmd_arr;
	char *path_temp;

	if (path_arr == NULL)
		return (NULL);
	cmd_arr = malloc(sizeof(char *) * path_len);
	if (cmd_arr == NULL)
	{
		perror("allocation failure");
		return (NULL);
	}

	k = 0;
	while (path_arr[k] != NULL)
	{
		path_size = _strlen(path_arr[k]);
		cmd_len = _strlen(cmd);
		path_temp = malloc(path_size + 1 + cmd_len + 1);
		if (path_temp == NULL)
		{
			perror("allocation failure");
			free(cmd_arr);
			return (NULL);
		}
		_strcpy(path_temp, path_arr[k]);
		_strcat(path_temp, "/");
		_strcat(path_temp, cmd);
		cmd_arr[k] = path_temp;
		k++;
	}
	cmd_arr[k] = NULL;
	return (cmd_arr);
}

/**
* cmd_status - checks for which command in the cmd_arr exists
* @cmd_arr: Pointer to an array of commands
* Return: The command that exists
*/

char *cmd_status(char **cmd_arr)
{
	struct stat st;
	char *cmd;
	int i;

	i = 0;
	if (cmd_arr == NULL)
		return (NULL);
	while (cmd_arr[i])
	{
		if (stat(cmd_arr[i], &st) == 0)
		{
			cmd = _strdup(cmd_arr[i]);
			return (cmd);
		}
		i++;
	}
	return (NULL);
}

/**
* handle_path - handles path
* @cmd: The command to handle
* Return: The required command path or null if command does not exist
*/

char *handle_path(char *cmd)
{
	struct stat st;
	char **cmd_arr;
	char *cmd_temp;

	if (stat(cmd, &st) == 0)
		return (cmd);

	cmd_arr = path_append(cmd);
	if (cmd_arr == NULL)
		return (cmd);

	cmd_temp = cmd_status(cmd_arr);

	if (cmd_temp != NULL)
	{
		free(cmd);
		cmd = cmd_temp;
	}

	free_double(cmd_arr);
	return (cmd);
}

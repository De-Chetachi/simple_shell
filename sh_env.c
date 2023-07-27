#include "my_shell.h"
/**
* env_var - gets env variables
* Return: Env vars
*/
char **env_var()
{
	int i;
	int len = arr_len(environ);
	char **env = malloc(sizeof(char *) * len);


	i = 0;
	while (environ[i])
	{
		env[i] = _strdup(environ[i]);
		i++;
	}
	return (env);
}

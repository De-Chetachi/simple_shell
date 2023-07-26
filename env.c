#include "my_shell.h"

char **env_var()
{
	int i;
	int len = arr_len(environ);
	char **env = malloc(sizeof(char *) * len);

	i = 0;
	while (environ[i])
	{
		env[i] = strdup(environ[i]);
		i++;
	}
	return (env);
}

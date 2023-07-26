#include "my_shell.h"
#include <stdlib.h>
#include <string.h>

/**
 * _unsetenv - this function deletes an enviromet variable
 * @name: name of variable to be deleted
 * Return: 0
 */
int _unsetenv(const char *name)
{
	int NA_len = strlen(name);
	int i, j;

	if (name == NULL || name[0] == '\0')
	{
		return (-1);
	}
	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], name, NA_len) == 0 && environ[i][NA_len] == '=')
		{
			for (j = i; environ[j] != NULL; j++)
			{
				environ[j] = environ[j + 1];
			}
			return (0);
		}
	}
	return (0);
}

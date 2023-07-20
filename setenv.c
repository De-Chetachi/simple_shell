#include <stdlib.h>
#include <string.h>
#include <stdio.h>
/**
 * _setenv - This function adds to or modify the env vari
 * @name: name of the variable to be set
 * @value: value of the variable to be set
 * @overwrite: indicates if variable already exist or not
 * Return: 0
 */

int _setenv(const char *name, const char *value, int overwrite)
{
	size_t lengthOFname = strlen(name);
	size_t i, lengthOFvalue = strlen(value);
	size_t size = lengthOFname + lengthOFvalue + 2;
	char *envvar;
	char *p;

	if (name == NULL || name[0] == '\0' || strchr(name, '=') != NULL)
		return (-1);
	if (getenv(name) != NULL && overwrite == 0)
		return (0);
	envvar = (char *)malloc(size);
	if (envvar == NULL)
	{
		return (-1);
	}
	p = envvar;
	for (i = 0; i < lengthOFname; i++)
	{
		*p++ = name[i];
	}
	*p++ = '=';
	for (i = 0; i < lengthOFvalue; i++)
	{
		*p++ = value[i];
	}
	*p = '\0';
	if (putenv(envvar) != 0)
	{
		free(envvar);
		return (-1);
	}
	p = envvar;

	while (*p)
	{
		putchar(*p++);
	}
	putchar('\n');
	return (0);
}

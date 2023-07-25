#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "my_shell.h"

/**
 * _setenv - This function adds to or modify the env vari
 * @name: name of the variable to be set
 * @value: value of the variable to be set
 * @overwrite: indicates if variable already exist or not
 * Return: 0
 */

int _setenv(const char *name, const char *value, int overwrite)
{
	int my_result;
	const char *p = name;

	if (name == NULL || name[0] == '\0' || strchr(name, '=') != NULL)
		return (-1);
	if (getenv(name) != NULL && overwrite == 0)
		return (0);
	my_result = setenv(name, value, overwrite);
	if (my_result != 0)

	{
		perror("Failed to set environment variable");
		return (-1);
	}

	while (*p)
	{
		putchar(*p++);
	}
	putchar ('=');
	p = value;
	while (*p)
	{
		putchar(*p++);
	}
	putchar('\n');
	return (0);
}

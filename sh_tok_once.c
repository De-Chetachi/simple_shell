#include "my_shell.h"

/**
* tok_once - tokenizes a string one time
* @str: string to be tokenized
* @delim: The deliminating string
* Return: str if delim not found, the first
* half on the string if delim is found
*/
char *tok_once(char *str, char *delim)
{
	char *tok;

	if (str == NULL || delim == NULL)
		return (NULL);
	tok = strstr(str, delim);
	if (tok)
	{
		*tok = '\0';
	}
	return (str);
}

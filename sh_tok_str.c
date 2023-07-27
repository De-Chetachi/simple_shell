#include "my_shell.h"
/**
* tok_len - finds how many tokens are present in a string
* @str: The string
* @delim: Delimeter
* Return: Integer
*/

int tok_len(char *str, char *delim)
{
	int i = 0;
	int bits;
	char *str_cpy_b;
	char *strcpyb_temp;
	char *token_b;
	int bytes = 1;

	if (str == NULL || delim == NULL)
		return (i);
	bits = _strlen(str);

	str_cpy_b = _strdup(str);
	if (str_cpy_b == NULL)
		return (i);

	strcpyb_temp = str_cpy_b;

	token_b = strchr_str(str_cpy_b, delim);

	i = 0;
	while (token_b != NULL && i < bits)
	{
		*token_b = '\0';
		if (_strcmp(str_cpy_b, "\0") != 0)
			i++;

		str_cpy_b = token_b + bytes;
		token_b = strchr_str(str_cpy_b, delim);
	}
	if (_strcmp(str_cpy_b, "\0") != 0)
		i++;
	i++;
	free(strcpyb_temp);

	return (i);
}

/**
* tok_str - tokenizes a string
* @str: Pointer to the string
* @delim: Deliminating string
* @tok_size: Pointer to an int fro storing arr_len
* Return: An array of strings
*/

char **tok_str(char *str, char *delim, int *tok_size)
{
	char **tokens;
	char *str_cpy, *token, *strcpy_temp;
	int bytes = 1, i;

	if (str == NULL || delim == NULL)
		return (NULL);

	str_cpy = _strdup(str);
	if (str_cpy == NULL)
		return (NULL);
	strcpy_temp = str_cpy;
	*tok_size = tok_len(str, delim);
	tokens = malloc(sizeof(char *) * (*tok_size));
	if (tokens == NULL)
	{
		free(strcpy_temp);
		return (NULL);
	}
	token = strchr_str(str_cpy, delim);
	i = 0;
	while (token != NULL && i < (*tok_size))
	{
		*token = '\0';
		if (_strcmp(str_cpy, "\0") != 0)
		{
			tokens[i] = _strdup(str_cpy);
			i++;
		}
		str_cpy = token + bytes;
		token = strchr_str(str_cpy, delim);
	}
	if (strcmp(str_cpy, "\0") != 0)
	{
		tokens[i] = _strdup(str_cpy);
		i++;
	}
	tokens[i] = NULL;
	free(strcpy_temp);
	return (tokens);
}

#include "my_shell.h"

/**
* tok_str - tokenizes a string
* @str: Pointer to the string
* Return: An array of strings
*/

char **tok_str(char *str, char *delim, int *tok_size)
{
	char **tokens;
	char store[BUFF_SIZE];
	char store_b[BUFF_SIZE];
	char *str_cpy = strcpy(store, str);
	char *str_cpy_b = strcpy(store_b, str);
	char *token;
	char *token_b;
	int bytes = strlen(delim);
	int i;

	if (str == NULL || delim == NULL)
		return (NULL);
	*tok_size = 0;	
	token_b = strstr(str_cpy_b, delim);

	while (token_b != NULL && *tok_size < BUFF_SIZE)
	{
		*token_b = '\0';

		if (strcmp(str_cpy_b, "\0") != 0)
			(*tok_size)++;

		str_cpy_b = token_b + bytes;
		token_b = strstr(str_cpy_b, delim);
	}
	if (strcmp(str_cpy_b, "\0") != 0)
		(*tok_size)++;
	(*tok_size)++;

	tokens= malloc(sizeof(char *) * (*tok_size));
	if (tokens == NULL)
	{
		free(str);
		return (NULL);
	}

	token = strstr(str_cpy, delim);
	i = 0;
	while (token != NULL && i < (*tok_size))
	{
		*token = '\0';
		if (strcmp(str_cpy, "\0") != 0)
		{
			tokens[i] = strdup(str_cpy);
			i++;
		}
		str_cpy = token + bytes;
		token = strstr(str_cpy, delim);
	}
	if (strcmp(str_cpy, "\0") != 0)
	{
		tokens[i] = strdup(str_cpy);
		i++;
	}
	tokens[i] = NULL;

	return (tokens);
}

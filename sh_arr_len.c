#include "my_shell.h"

/**
* arr_len - calculates the length of a vector
* @vector: the vector
* Return: Integer
*/

int arr_len(char **vector)
{
	int len = 0, i;


	if (vector != NULL)
	{
		for (i = 0; vector[i]; i++)
			len++;
	}
	return (len);
}

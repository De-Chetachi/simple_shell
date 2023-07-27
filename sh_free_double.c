#include "my_shell.h"
/**
* free_double - frees a two dimensional array
* @vector: Pointer to array
* Return: nothing
*/

void free_double(char **vector)
{
	int i;
	int len = arr_len(vector);

	i = 0;
	if (vector)
	{
		while (i < len)
		{
			free(vector[i]);
			i++;
		}
		free(vector);
	}
}

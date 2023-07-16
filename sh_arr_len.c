#include "my_shell.h"

/**
*
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

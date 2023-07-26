#include "my_shell.h"

/**
* get_line - gets line from standard input and stores it in a buffer
*
* Return: pointer to the bufffer
*/

char *read_line()
{
	char *std_buff = NULL;
	size_t buff_len;
	ssize_t bytes;

	bytes = getline(&std_buff, &buff_len, stdin);

	if (bytes == -1)
	{
		free(std_buff);
		free_double(path_arr);
		exit(EXIT_SUCCESS);
	}

	if (std_buff[bytes - 1] == '\n')
	{
		std_buff[bytes - 1] = '\0';
	}
	return (std_buff);
}

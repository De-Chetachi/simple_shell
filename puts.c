#include "my_shell.h"
#include "sh_utils.h"

/**
* _puts - prints a string
* @str: The pointer to the  string to be printed
* Return: Null
*/
void _puts(char *str)
{
	int	i;

	for	(i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
	_putchar('\n');
}

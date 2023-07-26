#include "sh_utils.h"
/**
* _strlen - calculates the length of a string
* @s: The pointer to the string whose length we want to calculate
* Return: The length of the string
*/

int	_strlen(char	*s)
{
	int	a;
	int	i;

	a	=	0;
	if (s)
	{
		for (i = 0; s[i] != '\0'; i++)
		{
			a++;
		}
	}
	return	(a);
}

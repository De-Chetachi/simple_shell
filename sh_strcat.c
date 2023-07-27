#include "sh_utils.h"

/**
* _strcat - concartenates two strings
* @dest: Pointer to the first string
* @src: Pointer to the second string
* Return: a pointer to the resulting string
*/

char	*_strcat(char	*dest,	char	*src)
{
	int	i;
	int	j;

	if (dest == NULL)
		return (NULL);

	for	(i = 0; dest[i] != '\0'; i++)
		;
	if (src)
	{
		for	(j = 0; src[j] != '\0'; j++)
		{
			dest[i]	=	src[j];
			i++;
		}
	}
	dest[i]	=	'\0';

	return	(dest);
}

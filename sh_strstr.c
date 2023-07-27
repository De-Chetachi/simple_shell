#include "sh_utils.h"

/**
* _strstr - finds the first occurrence of the substring
* needle in the string haystack
* @haystack: A pointer to haystach
* @needle: A pointer to needle
* Return: A pointer to the beginning of the located substring
* NULL if the substring is not found
*/

char	*_strstr(char *haystack, char *needle)
{
	if (haystack == NULL || needle == NULL)
		return (NULL);

	for	(; *haystack != '\0'; haystack++)
	{
		char	*a	=	haystack;
		char	*b	=	needle;

		while	(*a == *b && *b != '\0')
		{
			a++;
			b++;
		}
		if	(*b == '\0')
			return	(haystack);
	}
	return	(NULL);

}

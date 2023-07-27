#include "sh_utils.h"

/**
* _strchr -This function locates a character in a string
* @s: Pointer to a string
* @c: Character to be located
* Return: Pointer to the first occurrence of the character c in the string s
* or NULL if the character is not found
*/
char *_strchr(char *s, char c)
{
	int i;

	if (!s)
		return (NULL);

	for (i = 0; s[i] >= '\0'; i++)
	{
		if (s[i] == c)
		{
			return (s + i);
		}
	}

	return (NULL);
}

#include "my_shell.h"

/**
* strchr_str - finds the first occurrance on any character from seeds in fruit
* @fruit: A pointer to a string
* @seeds: An array of characters to look for in fruit
* Return: the first occurrance of an element of seed
* in fruit or null if no char is found
*/

char *strchr_str(char *fruit, char *seeds)
{
	if (!fruit || !seeds)
		return (NULL);


	for (; *fruit != '\0'; fruit++)
	{
		char *a = fruit;
		char *b = seeds;

		while (*b != '\0')
		{
			if (*b == *a)
				return (fruit);
			b++;
		}
	}
	return (NULL);
}

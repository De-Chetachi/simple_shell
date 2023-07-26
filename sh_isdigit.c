#include "sh_utils.h"
/**
* _isdigit - checks if an input is digit
* @c: The integer to be considered
* Return: 1 if c is a digit, 0 otherwise
*/

int	_isdigit(int	c)
{
	if	((c	<=	57)	&&	(c	>=	48))
	{
		return	(1);
	}
	else
	{
		return	(0);
	}
}

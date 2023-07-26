#include <stdio.h>
#include "my_shell.h"

/**
 * main - To test our custom setenv function
 * Return: 0
 */

int main(void)
{
    const char *NAMEofVARIABLE = "OUR_SHELL_PROJECT_VARIABLE";
    const char *VALUEofVARIABLE = "Hello, from Cheta and Dami!";

    int result = _setenv(NAMEofVARIABLE, VALUEofVARIABLE, 1);
    if (result == 0)
    {
        printf("%s has been set to: %s\n", NAMEofVARIABLE, VALUEofVARIABLE);
    }
    else
    {
        printf("Failed to set %s.\n", NAMEofVARIABLE);
    }

    return 0;
}


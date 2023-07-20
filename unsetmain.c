#include <stdio.h>
#include "my_shell.h"

/**
 * main - this main function test the unsetenv func
 * Return; 0
 */
int main(void)
{
    const char *variableName = "OUR_SHELL_VARIABLE";
    int result;
    char *variableValue = getenv(variableName);

    if (variableValue != NULL)
    {
	    printf("%s is currently set to: %s\n", variableName, variableValue);
    }
    else
    {
	    printf("%s is not set.\n", variableName);
    }
    result = _unsetenv(variableName);
    if (result == 0)
    {
	    printf("%s has been unset.\n", variableName);
    }
    else
    {
	    printf("Failed to unset %s.\n", variableName);
    }
    variableValue = getenv(variableName);
    if (variableValue != NULL)
    {
	    printf("%s is still set to: %s\n", variableName, variableValue);
    }
    else
    {
	    printf("%s is not set anymore.\n", variableName);
    }
    return 0;
}


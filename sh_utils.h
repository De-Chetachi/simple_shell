#ifndef SH_UTILS_H
#define SH_UTILS_H

#include "my_shell.h"
/*return integers*/
int _strlen(char	*s);
int _putcher(char c);
char *_strcat(char	*dest,	char	*src);
char *_strchr(char *s, char c);
int _strcmp(char	*s1,	char	*s2);
int _strncmp(char   *s1,    char    *s2, int n);
char *_strcpy(char *dest, char *src);
char *_strstr(char *haystack, char *needle);
char *_strdup(char *str);
int _atoi(char *s);
int _isdigit(int    c);

#endif

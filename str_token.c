#define SHELL_H
#include "shell.h"
/**
 * _strtok - it separates strings with delimiters
 * @line: It is a pointer to array we receive in getline.
 * @delim: It is a characters we mark off string in parts.
 * Return: the pointer to the created token
*/
char *_strtok(char *line, char *delim)
{
int b;
static char *str;
char *copystr;
if (line != NULL)
str = line;
for (; *str != '\0'; str++)
{
for (b = 0; delim[b] != '\0'; b++)
{
if (*str == delim[b])
break;
}
if (delim[b] == '\0')
break;
}
copystr = str;
if (*copystr == '\0')
return (NULL);
for (; *str != '\0'; str++)
{
for (b = 0; delim[b] != '\0'; b++)
{
if (*str == delim[b])
{
*str = '\0';
str++;
return (copystr);
}
}
}
return (copystr);
}

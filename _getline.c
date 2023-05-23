#define SHELL_H
#include "shell.h"
#include <stddef.h>
#include <stdlib.h>
/**
* _getline - read the line from the prompt.
* @data: then struct for the program's data
*
* Return: the reading and  the counting bytes.
*/
int _getline(data_of_program *data)
{
char buff[BUFFER_SIZE] = {'\0'};
static char *array_commands[10] = {NULL};
static char array_operators[10] = {'\0'};
ssize_t bytes_read, a = 0;
/* check it does not exist more commands in the array */
/* also and checks the logical operators */
if (!array_commands[0] || (array_operators[0] == '&' && errno != 0) ||
(array_operators[0] == '|' && errno == 0))
{
/* then free memory allocated in the array if it exists */
for (a = 0; array_commands[a]; a++)
{
free(array_commands[a]);
array_commands[a] = NULL;
}
/* also read file descriptor int to buff */
bytes_read = read(data->file_descriptor, &buff, BUFFER_SIZE - 1);
if (bytes_read == 0)
return (-1);
/* then split lines \n or ; */
a = 0;
{
array_commands[a] = str_duplicate(_strtok(a ? NULL : buff, "\n;"));
/*checks and split for && and || operators*/
a = check_logic_ops(array_commands, a, array_operators);
} while (array_commands[a++]);
}
/*obtain the next command (command 0) and remove it for the array*/
data->input_line = array_commands[0];
for (a = 0; array_commands[a]; a++)
{
array_commands[a] = array_commands[a + 1];
array_operators[a] = array_operators[a + 1];
}
return (str_length(data->input_line));
}
/**
* check_logic_ops - always check and split for && and || operators
* @array_commands: array of the commands.
* @a: index in the array_commands to be checked
* @array_operators: array of the logical operators for each previous command
*
* Return: index of last command in the array_commands.
*/
int check_logic_ops(char *array_commands[], int a, char array_operators[])
{
char *temp = NULL;
int b;
/* checks for & char in the command line*/
for (b = 0; array_commands[a] != NULL  && array_commands[a][b]; b++)
{
if (array_commands[a][b] == '&' && array_commands[a][b + 1] == '&')
{
/* split line when chars && was found */
temp = array_commands[a];
array_commands[a][b] = '\0';
array_commands[a] = str_duplicate(array_commands[a]);
array_commands[a + 1] = str_duplicate(temp + b + 2);
a++;
array_operators[a] = '&';
free(temp);
b = 0;
}
if (array_commands[a][b] == '|' && array_commands[a][b + 1] == '|')
{
/* split line when chars || was found */
temp = array_commands[a];
array_commands[a][b] = '\0';
array_commands[a] = str_duplicate(array_commands[a]);
array_commands[a + 1] = str_duplicate(temp + b + 2);
a++;
array_operators[a] = '|';
free(temp);
b = 0;
}
}
return (a);
}

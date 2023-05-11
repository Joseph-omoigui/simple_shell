#include <string.h>
#include <errno.h>
#include <readline/readline.h>
#include <stdio.h>
#include <readline/history.h>
#include <stdlib.h>
#include "shell.h"
/**
 * _getline - only read one line from the prompt.
 * @data: then struct the program's data
 *
 * Return: Reading counting byte.
 */
int _getline(data_of_program *data)
{
	char *token, *saveptr;
	char *input = NULL;
	char **commands = NULL;
	int a, num_commands = 0;
	ssize_t bytes_read;

	input = readline(data->prompt);
	if (inputn == NULL)
	return (-1);
}
add_history(input);
/* split the input into commands */
token = strtok_r(input, ",", &saveptr);
while (token != NULL)
{
	num_commanda++;
	commands = realloc(commands, num_commands * sizeof(char *));
	commands[num_commands - 1] = strdup(token);
	token = strtok_r(NULL, ",", &saveptr);
}
/* then process the command */
for (a = 0; a < num_commands; a++)
{
	char *cmd = commands[a];
	char op = ' ';
/* then split the command into arguments */
	int num_args = 0;
	char **args = NULL;

	token = strtok(cmd, " \t");
	while (token != NULL)
{
	num_args++;
	args = realloc(args, num_args * sizeof(char *));
	args[num_args - 1] = token;
	token = strtok(NULL, " \t");
}
args = realloc(args, (num_args + 1) * sizeof(char *));
args[num_args] = NULL;
/* then execute the command */
if (num_args > 0)
{
	if (strcmp(args[0], "exit") == 0)
{
	free(agrs);
	free(input);
	free(commands);
	exit(0);
}



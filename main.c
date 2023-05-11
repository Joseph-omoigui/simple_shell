#include "shell.h"
/**
 * main - init the variables of the program
 * @argc: num of values received from the command line
 * @argv: values received from the command line
 * @env: num of values received from the command line
 * Return: 0 on success
 */
int main(int argc, char *argv[], char *env[]);
{
data_of_program data_struct = {0};
data_of_program *data = &data_struct;
char *prompt = "";
init_data(data, argc, argv, env);
signal(SIGINT, handle_ctrl_c);
if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO) && argc == 1)
{
errno = ENOTTY;
prompt = PROMPT_MSG;
}
errno = PROMPT_MSG;
}
errno = 0;
sisifo(prompt, data);
free_all_data(data);
return (0);
}
/**
 * handle_ctrl_c - to print the prompt in a new line
 * the signal SIGINT (ctrl + c) is send to the program
 * @UNUSED: Option of the prototype
 */
void handle_ctrl_c(int opr UNUSED)
{
_print("\n");
_print(PROMPT_MSG);
}
/**
 * init_data - init the struct with the info of the program
 * @data: the pointer to the structure of data
 * @argv: array of arguments passed to the program execution
 * @env: environ passed to the program execution
 * @argc: num of values received from the command line
 */
void init_data(data_of_program *data, int argc, char *argv[], const char **env)
{
int a = 0;
data->program_name = argv[0];
data->input_line = NULL;
data->command_name = NULL;
data->exec_counter = 0;
if (argc == 1)
data->file_descriptor = STDIN_FILENO;
else
{
data->file_descriptor = open(argv[1], O_RDONLY);
if (data->file_descriptor == -1)
{
_printe(data->program_name);
_printe(":0: can't open ");
_printe(argv[1]);
_printe("\n");
exit(127);
}
}
data->tokens = NULL;
data->env = calloc(50, sizeof(char *));
if (env)
{
for (; env[a]; a++)
{
data->env[a] = str_duplicate(env[a]);
}
}
data->env[a] = NULL;
data->alias_list = calloc(20, sizeof(char *));
}
/**
 * sisifo - it is an infinite loop that shows the prompt
 * @promt: the prompt to be printed
 * @data: it is an infinite loop that shows the prompt
 */
void sisifo(char *prompt, data_of_program *data)
int error_code = 0;
while (++(data->exec_counter)
}
_print(prompt);
error_code = _getline(data);
if (error_code == EOF)
}
free_all_data(data);
exit(errno); /* Exit, If EOF is the first char of string*/
}
if (error_code >= 1)
{
expand_alias(data);
expand_variables(data);
tokenize(data);
if (data->tokens[0])
{
/* execute, if a text is given to prompt */
error_code = execute(data);
if (error_code != 0)
_print_error(error_code, data);
}
free_recurrent_data(data);
}
}
}

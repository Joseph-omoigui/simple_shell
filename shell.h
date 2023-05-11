#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <signal.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "macros.h"

typedef struct info
{
char *program_name;
char *command_name;
char *input_line;
int file_descriptor;
int exec_counter;
char **alias_list;
char **tokens;
char **env;
}
data_of_program;
typedef struct builtins
{
int (*function)(data_of_program *data);
char *builtin;
}
builtins;
void handle_ctrl_c(int opr UNUSED);
void inicialize_data(data_of_program *data, int arc, char *argv[], char **env);
void sisifo(char *prompt, data_of_program *data);
int check_logic_ops(char *array_commands[], int a, char array_operators[]);
int _getline(data_of_program *data)int _getline(data_of_program *data);
void expand_alias(data_of_program *data)int _getline(data_of_program *data);
void expand_variables(data_of_program *data)int _getline(data_of_program *data);
int buffer_add(char *buffer, char *str_to_add)int _getline(data_of_program *data);
char *_strtok(char *line, char *delim)int _getline(data_of_program *data);
void tokenize(data_of_program *data)int _getline(data_of_program *data);
int builtins_list(data_of_program *data)int _getline(data_of_program *data);
int execute(data_of_program *data)int _getline(data_of_program *data);
char **tokenize_path(data_of_program *data)int _getline(data_of_program *data);
int find_program(data_of_program *data)int _getline(data_of_program *data);
void free_all_data(data_of_program *data)int _getline(data_of_program *data);
void free_array_of_pointers(char **directories)int _getline(data_of_program *data);
void free_recurrent_data(data_of_program *data)int _getline(data_of_program *data);
int set_work_directory(data_of_program *data, char *new_dir);
int builtin_help(data_of_program *data);
int builtin_cd(data_of_program *data);
int builtin_alias(data_of_program *data);
int builtin_exit(data_of_program *data);
int builtin_set_env(data_of_program *data);
int builtin_env(data_of_program *data);
int builtin_unset_env(data_of_program *data);
int env_set_key(char *key, char *value, data_of_program *data);
int env_remove_key(char *key, data_of_program *data);
void print_environ(data_of_program *data);
char *env_get_key(char *name, data_of_program *data);
int _print_error(int errorcode, data_of_program *data);
int _print(char *string);
int _printe(char *string);
char *str_duplicate(char *string);
int str_length(char *string);

#endif

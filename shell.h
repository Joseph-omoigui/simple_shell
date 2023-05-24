#ifndef _SHELL_H_
#define _SHELL_H_

#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>



/* command chain */
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

/* 1 if using system getline() */
#define USE_GETLINE 0
#define USE_STRTOK 0
#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096
extern char **environ;

/* to convert numbers */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2



/* to read and write buffers */
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1
#define READ_BUF_SIZE 1024

/**
 * struct liststr - singly linked list
 * @next: points to the next node
 * @num: Means a number field
 * @str: Means a string
 */
typedef struct liststr
{
	struct liststr *next;
	char *str;
	int num;
} list_t;

typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf; /* pointer to cmd ; chain buffer, for memory mangement */
	int cmd_buf_type; /* CMD_type ||, &&, ; */
	int readfd;
	int histcount;
} info_t;

/**
 * struct passinfo - contains arguements to pass into a function,
 * maintaining identical prototype for function pointer struct
 * 
 * @histcount: the history line number count
 * @argv:an array of strings gotten from arg
 * @path: a string path for the current command
 * @argc: argument count
 * @err_num: error code for exit functions
 * @linecount_flag: count this line of input
 * @fname: program filename
 * @env: linked list local copy of environ
 * @line_count: error count
 * @environ: modified copy of environ from LL env
 * @history: history node
 * @alias: alias node
 * @env_changed: on if environ was changed
 * @status: the return status of the last executed command
 * @cmd_buf: address of pointer to cmd_buf
 * @cmd_buf_type: CMD_type ||, &&, ;
 * @readfd: the fd from which to read line input
 * @arg: string gotten from getline having arguements
 */

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
		0, 0, 0}

/**
 * struct builtin - contains a builtin string and related function
 * @type: the builtin command flag
 * @func: the function
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;


/* toem_shloop.c */

int find_builtin(info_t *);
void find_cmd(info_t *);
int hsh(info_t *, char **);
void fork_cmd(info_t *);

/* loophsh.c */
int loophsh(char **);

/* toem_parser.c */
int is_cmd(info_t *, char *);
char *dup_chars(char *, int, int);
char *find_path(info_t *, char *, char *);


/* toem_errors.c */
void printinputstr(char *);
int writechar(char);
int _putde(char c, int fd);
int putsde(char *str, int fd);

/* toem_string.c */
int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);

/* toem_string1.c */
char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);

/* exits.c */
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);

/* realloc.c */
char *_memset(char *, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);

/* tokenizer.c */
char **strtow(char *, char *);
char **strtow2(char *, char);

/* memory.c */
int bfree(void **);

/* atoi.c */
int responsive(info_t *);
int delimitter(char, char *);
int alpha1(int);
int string2int(char *);



/* builtin.c */
int _exitme(info_t *);
int _cdnd(info_t *);
int _cdpwd(info_t *);

/* errmessages.c */
int _erratoi(char *);
void print_error(info_t *, char *);
int print_d(int, int);
char *convert_number(long int, int, int);
void remove_comments(char *);

/* internal2.c */
int _historylist(info_t *);
int _aliaslist(info_t *);

/* getline.c */
ssize_t get_input(info_t *);
int _getline(info_t *, char **, size_t *);
void sigintHandler(int);

/* infor.c */
void clear_info(info_t *);
void set_info(info_t *, char **);
void free_info(info_t *, int);

/* atmosphere.c */
char *_getenv(info_t *, const char *);
int currentenv(info_t *);
int setnewenv(info_t *);
int unsetnewenv(info_t *);
int populate_new_env(info_t *);

/* halloween.c */
char **get_environ(info_t *);
int _unsetenv(info_t *, char *);
int _setenv(info_t *, char *, char *);

/* history.c */
int build_history_list(info_t *info, char *buf, int linecount);
char *get_history_file(info_t *info);
int read_history(info_t *info);
int renumber_history(info_t *info);
int write_history(info_t *info);

/* vars.c */
int is_chain(info_t *, char *, size_t *);
void check_chain(info_t *, char *, size_t *, size_t, size_t);
int replace_alias(info_t *);
int replace_vars(info_t *);
int replace_string(char **, char *);

/* lists.c */
list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
size_t print_list_str(const list_t *);
int delete_node_at_index(list_t **, unsigned int);
void free_list(list_t **);

/* lists1.c */
size_t list_len(const list_t *);
char **list_to_strings(list_t *);
size_t print_list(const list_t *);
list_t *node_starts_with(list_t *, char *, char);
ssize_t get_node_index(list_t *, list_t *);

#endif
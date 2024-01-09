#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/* for read/write buffers */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* for command chaining */
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

/* for convert_number() */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/* 1 if using system getline() */
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;


/**
 * struct liststr - singly linked list
 * @num: the number field
 * @str: a string
 * @next: points to the next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 *struct passinfo - contains pseudo-arguements to pass into a function,
 *		allowing uniform prototype for function pointer struct
 *@arg: a string generated from getline containing arguements
 *@argv: an array of strings generated from arg
 *@path: a string path for the current command
 *@argc: the argument count
 *@line_count: the error count
 *@err_num: the error code for exit()s
 *@linecount_flag: if on count this line of input
 *@fname: the program filename
 *@env: linked list local copy of environ
 *@environ: custom modified copy of environ from LL env
 *@history: the history node
 *@alias: the alias node
 *@env_changed: on if environ was changed
 *@status: the return status of the last exec'd command
 *@cmd_buf: address of pointer to cmd_buf, on if chaining
 *@cmd_buf_type: CMD_type ||, &&, ;
 *@readfd: the fd from which to read line input
 *@histcount: the history line number count
 */
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

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 *struct builtin - contains a builtin string and related function
 *@type: the builtin command flag
 *@func: the function
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;


/* toem_shloop.c */


/* toem_parser.c */
list_t *prepend_node(list_t **head, const char *str, int num);
list_t *append_node(list_t **head, const char *str, int num);
size_t display_list_str(const list_t *h);
int remove_node_at_index(list_t **head, unsigned int index);
void release_list(list_t **head_ptr);

/* loophsh.c */


/* toem_errors.c */
void print_to_stderr(char *str);
int write_char_to_stderr(char c);
int write_char_to_fd(char c, int fd);
int print_to_fd(char *str, int fd);

/* toem_strings.c */
int calculate_string_length(char *str);
int compare_strings(char *str1, char *str2);
char *check_prefix(const char *haystack, const char *needle);
char *concatenate_strings(char *dest, char *src);

/* toem_string.c */
char *copy_string(char *destination, char *source);
char *duplicate_string(const char *str).;
void print_string(char *str);
int print_char(char c);


/* toem_exits.c */
char *copy_string(char *dest, char *src, int n);
char *concatenate_strings(char *dest, char *src, int n);
char *locate_char(char *s, char c);

/* toem_tokenizer.c */
char **split_string(char *input_str, char *delimiter);
char **split_string2(char *input_str, char delimiter);


/* toem_realloc.c */
char *fill_memory(char *mem_area, char byte, unsigned int num_bytes);
void free_strings(char **strings);
void *reallocate_memory(void *old_ptr, unsigned int old_size, unsigned int new_size);


/* toem_memory.c */
int free_and_nullify(void **pointer);

/* toem_atoi.c */
int print_env(info_t *shell_info);
char *get_env_var(info_t *shell_info, const char *var_name);
int set_env_var(info_t *shell_info);
int unset_env_var(info_t *shell_info);
int fill_env_list(info_t *shell_info);

/* toem_errors1.c */
int convert_str_to_int(char *str);
void display_error(info_t *info, char *error_str);
int print_decimal(int input, int fd);
char *convert_num_to_str(long int num, int base, int flags);
void strip_comments(char *buf);

/* toem_builtin.c */
int shell_exit(info_t *shell_info);
int shell_cd(info_t *shell_info);
int shell_help(info_t *shell_info);

/* toem_builtin1.c */
int display_history(info_t *shell_info);
int remove_alias(info_t *shell_info, char *alias_str);
int add_alias(info_t *shell_info, char *alias_str);
int output_alias(list_t *alias_node);
int shell_alias(info_t *shell_info);


/*toem_getline.c */
ssize_t buffer_commands(info_t *info, char **buf, size_t *len);
ssize_t fetch_input(info_t *info);
ssize_t read_buffer(info_t *info, char *buf, size_t *i);
int fetch_line(info_t *info, char **ptr, size_t *length);
void block_ctrl_c(__attribute__((unused))int sig_num);

/* toem_getinfo.c */
void initialize_info(info_t *info);
void setup_info(info_t *info, char **arg_vector);
void release_info(info_t *info, int all);

/* toem_environ.c */
int print_env(info_t *shell_info);
char *get_env_var(info_t *shell_info, const char *var_name);
int set_env_var(info_t *shell_info);
int unset_env_var(info_t *shell_info);
int fill_env_list(info_t *shell_info);

/* toem_getenv.c */
char **fetch_environ(info_t *shell_info);
int remove_env_var(info_t *shell_info, char *var);
int set_env_var(info_t *shell_info, char *var, char *value);

/* toem_history.c */
char *fetch_history_file(info_t *shell_info);
int save_history(info_t *shell_info);
int load_history(info_t *shell_info);
int add_to_history_list(info_t *shell_info, char *buffer, int linecount);
int update_history_numbers(info_t *shell_info);

/* toem_lists.c */
list_t *prepend_node(list_t **head, const char *str, int num);
list_t *append_node(list_t **head, const char *str, int num);
size_t display_list_str(const list_t *h);
int remove_node_at_index(list_t **head, unsigned int index);
void release_list(list_t **head_ptr);

/* toem_lists1.c */
size_t calculate_list_length(const list_t *h);
char **convert_list_to_strings(list_t *head);
size_t display_list(const list_t *h);
list_t *find_node_starting_with(list_t *node, char *prefix, char c);
ssize_t find_node_index(list_t *head, list_t *node);

/* toem_vars.c */
int is_chain_delimeter(info_t *info, char *buf, size_t *p);
void verify_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len);
int substitute_alias(info_t *info);
int substitute_vars(info_t *info);
int substitute_string(char **old, char *new);

#endif

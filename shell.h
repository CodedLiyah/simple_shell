#define _SHELL_H_
#ifndef _SHELL_H_

#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/* when writing/read buffers */
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1
#define READ_BUF_SIZE 1024

/* when chaining commands */
#define CMD_AND		0
#define CMD_NORM	1
#define CMD_CHAIN	2
#define CMD_OR		3

/* when convert_number() */
#define CONVERT_UNSIGNED	1
#define CONVERT_LOWERCASE	2

/* 1 when using system getline() */
#define USE_STRTOK 0
#define CONVERT_LOWERCASE

#define HIST_MAX	4096
#define HIST_FILE	".simple_shell_history"

extern char **environ;

/**
 * struct liststr - singly linked list
 * @num: the number field
 * @str: a string
 * @next: points to the next node
 */
typedef struct liststr
{
	struct liststr *next;
	int num;
	char *str;

} list_t;

/**
 * struct command_info - contains pseudo-arguments to be passed into a function,
 * allowing a uniform prototype for function pointer struct.
 *
 * @input_fd: the file descriptor used for reading input lines.
 * @arg_string: a string generated from getline containing arguments.
 * @argv_array: an array of strings generated from arg_string.
 * @command_buffer_type: command type (e.g., ||, &&, ;).
 * @command_buffer: address of the pointer to the command buffer, set if chaining commands.
 * @history_node: the node representing the command history.
 * @env_modified: set if the environment variables were changed.
 * @history_line_count: the count of history line numbers.
 * @program_name: the name of the program file.
 * @count_line: if set, count this line of input.
 * @alias_node: the node representing command aliases.
 * @modified_env: a custom modified copy of the environment variables from the linked list.
 * @env_list: linked list representing a local copy of the environment variables.
 * @exit_code: the error code for exit() calls.
 * @line_number: the line number of the current command.
 * @command_path: a string representing the path for the current command.
 * @last_command_status: the return status of the last executed command.
 * @arg_count: the count of arguments.
 */

typedef struct passinfo
{
	char *path;
	char *arg;
	char **argv;
	list_t *history;
	list_t *alias;
	list_t *env;
	int env_changed;
	unsigned int line_count;
	int status;
	char **environ;
	int env_changed;
	int argc;

	int readfd;
	int cmd_buf_type; /* CMD_type ||, &&, ; */
	int histcount;
	char **cmd_buf; /* pointer to cmd ; chain buffer, for memory mangement */

} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 *struct builtin - A builtin string and similar function
 *@type: A builtin command flag
 *@func: A function
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;

/* simple_betty.c */
/**
 * _isalpha - Prints the alphabet
 * @i: The character to input
 *
 * Return:1 if i is alphabetic, 0 otherwise
 */

/** simple_path.c **/
/**
 * * handle_path - Handles the PATH
 * @info: the info struct
 * @pathstr: the PATH string
 * @handle: the command to find
 *
 * Return: full path of command if found or NULL
 */
char *handle_path(info_t *info, char *str, char *handle)


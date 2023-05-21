#ifndef SHELL_H
#define SHELL_H

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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct info_s {
    /* Add the required members used in shell_utils.c */
    int readfd; // Example member used in the interactive function
    char *history; // Example member used in the display_history function
    // Add any other members you need in other functions
} info_t;

/** convert_String.c **/
int new_interactive(info_t *info);
int check_delim(char dc, char *delim);
int is_custom_alpha(int ca);
int convert_string(char *sc);


/** shell_utils.c **/
int display_history(info_t *info);
int unset_alias(info_t *info, char *str);
int set_alias(info_t *info, char *str);
int print_alias(list_t *node);
int handle_alias(info_t *info);

/** builtin1.c **/
int _myhistory(info_t *);
int _myalias(info_t *);

/** environ.c **/
char *_getenv(info_t *, const char *);
int _myenv(info_t *);
int _mysetenv(info_t *);
int _myunsetenv(info_t *);
int populate_env_list(info_t *);

/** errors.c **/
void _eputs(char *);
int _eputchar(char);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);

/** errors1.c **/
int _erratoi(char *);
void print_error(info_t *, char *);
int print_d(int, int);
char *convert_number(long int, int, int);
void remove_comments(char *);

extern char **environ;

#endif

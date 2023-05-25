#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <stddef.h>
#include <sys/stat.h>
#include <signal.h>

int _putchar(char c);
void _puts(char *str);
int _strlen(char *s);
char *_strdup(char *str);
char *concat_all(char *name, char *sep, char *value);

char **splitstring(char *str, const char *delim);
void execute(char **argv);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);


extern char **environ;

/**
 * struct list_path - Linked list containing PATH directories
 * @dir: directory in path
 * @p: pointer to next node
 */

typedef struct list_path
{
	char *dir;
	struct list_path *p;
} list_path;


char *_getenv(const char *command);
list_path *append_node(list_path **list_head, char *str);
list_path *create_linked_list(char *path_str);
char find_pathname(char *file, list_path *head);
list_path *linkpath(char *path)

/**
 * struct buildin - pointer Structure representing a built-in command
 * @command: The name of the built-in command
 * @execute:  A pointer to the function that executes the built-in command
 */
typedef struct mybuild
{
	char *command;
	void (*execute)(char **);
} mybuild;

void(*checkbuild(char **arv))(char **arv);
int _atoi(char *s);
void exitt(char **arv);
void env(char **arv);
void _setenv(char **arv);
void _unsetenv(char **arv);

void freearv(char **arv);
void free_list(list_path *head);


#endif

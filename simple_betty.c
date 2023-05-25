#include "shell.h"


/**
 * _getenv - is a function that retrieves,
 * the value of an environment variable
 * @command: The name of the built-in command
 *
 * Return: Value of the string
 */
char *_getenv(const char *command)
{
	int x, y;
	char *val;

	if (!command)
	return (NULL);

	for (x = 0; environ[x]; x++)
	{
		y = 0;
		if (command[y] == environ[x][y])
		{
			while (command[y])
			{
			if (command[y] != environ[x][y])
				break;
			y++;
			}
			if (command[y] == '\0')
			{
			val = (environ[x] + y + 1);
			return (val);
			}
		}
	}
	return (0);
}


/**
 * append_node - Inserts a new node at the end of a list_path list
 * @list_head: Pointer to pointer to the head of the list
 * @str: Pointer to the string in previous last node
 *
 * Return: Address of the new element or node
 */

list_path *append_node(list_path **list_head, char *str)
{

	list_path *current;
	list_path *new_element;

	new_element = malloc(sizeof(list_path));

	if (!new_element || !str)
	{
	return (NULL);
	}

	new_element->dir = str;

	new_element->p = NULL;
	if (!*list)
	{
	*list = new_element;
	}
	else
	{
		current = *list;

		while (current->p)
		{

			current = current->p;
		}

		current->p = new_element;
	}

	return (*list);
}


/**
 * create_linked_list - creates a linked list for path directories
 * @path_str: String of path value
 *
 * Return: Pointer to linked list
 */

list_path *create_linked_list(char *path_str)
{
	list_path *h = '\0';
	char *t;
	char *cp = _strdup(path_str);

	t = strtok(cp, ":");
	while (t)
	{
		h = append_node(&h, t);
		t = strtok(NULL, ":");
	}

	return (h);
}

/**
 * find_pathname  -Locates the pathname of a filename
 * @file: The ame of file or command
 * @head: The  head of linked list of path directories
 *
 * Return: Pathname or NULL if no match
 */

char find_pathname(char *file, list_path *head)
{
	char *stringg;
	struct stat st;

	list_path *current = head;

	while (current)
	{

		stringg = concat_all(current->dir, "/", file);
		if (stat(stringg, &st) == 0)
		{
		return (stringg);
		}
		free(stringg);
		current = current->p;
	}

	return (NULL);
}

/**
 * free_list - Frees  list_t
 * @head: A pointer to linked list
 */

void free_list(list_path *head)
{
	list_path *stor;

	while (head)
	{
	stor = head->p;
	free(head->dir);
	free(head);
	head = stor;
	}
}

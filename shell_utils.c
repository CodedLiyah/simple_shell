#include "shell.h"

/**
 * display_history - Displays the command history with line numbers
 * @info: Structure containing potential argument.
 *
 *  Return: Always 0
 */
int display_history(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on failure
 */
int unset_alias(info_t *info, char *str)
{
	char *x, y;
	int r;

	x = _strchr(str, '=');
	if (!y)
	return (1);

	x = *y;
	*x = 0;
	r = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*x = y;
	return (r);
}

/**
 * set_alias - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int set_alias(info_t *info, char *str)
{
	char *equ;

	equ = _strchr(str, '=');
	if (!equ)
	return (1);
	if (!*++equ)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - prints an alias string
 * @node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int print_alias(list_t *node)
{
	char *equ = NULL, *alias = NULL;

	if (node)
	{
		equ = _strchr(node->str, '=');
		for (alias = node->str; alias <= equ; alias++)
			_putchar(*alias);
		_putchar('\'');
		_puts(equ + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * handle_alias - Handles the alias command
 * @info: Structure containingpotential arguments
 *
 *  Return: Always 0
 */
int handle_alias(info_t *info)
{
	int x = 0;
	char *y = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (x = 1; info->argv[i]; i++)
	{
		y = _strchr(info->argv[x], '=');
		if (y)
			set_alias(info, info->argv[x]);
		else
			print_alias(node_starts_with(info->alias, info->argv[x], '='));
	}

	return (0);
}


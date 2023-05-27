#include "shell.h"

/**
 * _myhistory - Shows the history list, one command by line, preceded
 *              with line numbers, starts at 0.
 * @info: Struct contains potential arguments. Used to maintain
 *        a constant function proto
 *  Return: Always 0
 */

int _myhistory(info_t *info)
{
print_list(info->history);
return (0);
}

/**
 * unset_alias - Makes an alias a string
 * @info: Struc parameter
 * @str: String alias
 *
 * Return: Always 0 on success, 1 on failure
 */

int unset_alias(info_t *info, char *str)
{
	char *pr, ch;
	int ret;

	pr = _strchr(str, '=');
	if (!pr)
		return (1);
	ch = *pr;
	*pr = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*pr = ch;
	return (ret);
}

/**
 * set_alias - Sets alias to a string
 * @info: Struct parameter
 * @str: The alias string
 *
 * Return: Always 0 on success, 1 on failure
 */

int set_alias(info_t *info, char *str)
{
	char *pr;

	pr = _strchr(str, '=');
	if (!pr)
		return (1);
	if (!*++pr)
	return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - Prints alias string
 * @node: Alias node
 *
 * Return: Always 0 on success, 1 on failure
 */

int print_alias(list_t *node)
{
	char *pr = NULL, *al = NULL;

	if (node)
	{
		pr = _strchr(node->str, '=');
		for (al = node->str; al <= pr; al++)
			_putchar(*al);
		_putchar('\'');
		_puts(pr + 1);
		_puts("'\n");
		return (0);
	}

	return (1);
}

/**
 * _myalias - Acts like the alias builtin
 * @info: Struct containing potential arguments. To maintain
 *          constant function prototype.
 *
 *  Return: Always 0
 */

int _myalias(info_t *info)
{
	int x = 0;
	char *pr = NULL;
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
	for (x = 1; info->argv[x]; x++)
	{
		pr = _strchr(info->argv[x], '=');
		if (pr)
			set_alias(info, info->argv[x]);
		else
			print_alias(node_starts_with(info->alias, info->argv[x], '='));
	}

	return (0);
}

#include "shell.h"

/**
 * _myenv - Puts the current environment
 * @info: Struct contains potential arguments. To maintain
 *          constant function
 * Return: Always 0
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - Optains the value of an environ variable
 * @info: Struct contains potential arguments. To maintain
 * @name: env var name
 *
 * Return: the value
 */

char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *pr;

	while (node)
	{
		pr = starts_with(node->str, name);
		if (pr && *pr)
			return (pr);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - Initialize a new env variable,
 *             or edit an existing variable
 *
 * @info: Struc contains potential arguments.To maintain
 *        constant function
 *
 * Return: Always 0
 */

int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - Remove an environment variable
 * @info: Struct contains potential arguments. To maintain
 *        constant function.
 *
 * Return: Always 0
 */

int _myunsetenv(info_t *info)
{
	int x;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}

	for (x = 1; x <= info->argc; x++)
		_unsetenv(info, info->argv[x]);

	return (0);
}

/**
 * populate_env_list - Populates env list
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *
 * Return: Always 0
 */

int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t x;

	for (x = 0; environ[x]; x++)
		add_node_end(&node, environ[x], 0);
	info->env = node;
	return (0);
}

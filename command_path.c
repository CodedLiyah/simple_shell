#include "shell.h"

/**
 * _myenv - prints current environment
 * @info: Structure used to maintain constant function prototype.
 *
 * Return : Always 0 (Success)
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - prints value of an environ variable
 * @name: env var name
 * @info: Structure used to maintain constant function prototype.
 *
 * Return: Always 0(Success)
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *j;

	while (node)
	{
		j = starts_with(node->str, name);
		if (j && *j)
			return (j);
		node = node->next;
	}
	return (NULL);
}

/**
 * _newenv- Begin new environment variable
 * @info: Structure used to maintain constant function prototype.
 * Return: Always 0 (Success) 
 */
int _newenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Invalid number of arguments\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _rmovenv- Removes environment variable
 * @info: Structure used to maintain constant function prototype.
 * Return : Always 0 (Success) 
 */
int _rmovenv(info_t *info)
{
	int a;

	if (info->arg == 1)
	{
		_eputs("Invalid number of arguments\n");
		return (1);
	}
	for (a = 1; a <= info->argc; a++)
		_unsetenv(info, info->argv[a]);

	return (0);
}

/**
 * populate_env_list - populates env linked list
 * @info: Structure used to maintain constant function prototype.
 * Return: Always 0 (Success)
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t a;

	for (a = 0; environ[a]; a++)
		add_node_end(&node, environ[a], 0);
	info->env = node;
	return (0);
}

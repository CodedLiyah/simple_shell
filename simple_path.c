#include "shell.h"

/**
 * handle_path - Handles the command for the path
 * @info_t: the info struct
 * @str: the PATH string
 * @handle: the cmd to find
 *
 * Return: full path of command if found or NULL
 */
char *handle_path(info_t *info, char *str, char *handle)
{
	int i = 0, curr_pos = 0;
	char *path;

	if (!str)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(handle, "./"))
	{
		if (is_handle(info, handle))
			return (handle);
	}
	while (1)
	{
		if (!str[i] || str[i] == ':')
		{
			path = dup_chars(str, curr_pos, i);
			if (!*path)
				_strcat(path, handle);
			else
			{
				_strcat(path, "/");
				_strcat(path, handle);
			}
			if (is_cmd(info, path))
				return (path);
			if (!str[i])
				break;
			curr_pos = i;
		}
		i++;
	}
	return (NULL);
}

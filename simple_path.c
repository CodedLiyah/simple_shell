#include "shell.h"
#include <stddef.h>

/**
 * on_command - Checks if a file is an executable command
 * @info: the info struct
 * @path: path to the file
 *
 * Return: 1 if true, 0 otherwise
 */
int on_command(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * double_ - duplicates characters
 * @pathstr: the PATH string
 * @on: starting index
 * @off: stopping index
 *
 * Return: pointer to new buffer
 */
char *double_(char *pathstr, int on, int off)
{
	static char buf[1024];
	int a = 0, j = 0;

	for (j = 0, a = on; a < off; a++)
		if (pathstr[a] != ':')
			buf[j++] = pathstr[a];
	buf[j] = 0;
	return (buf);
}

/**
 * handle_path - Handles the command for the path
 * @str: the PATH string
 * @handle: the cmd to find
 * @info :the info struct
 * Return: full path of command if found or NULL
 */
char *handle_path(info_t *info char *str, char *handle)
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

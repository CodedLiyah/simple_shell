#include "shell.h"

/**
 * is_cmd - It determines if a file is executable
 * @info: An info struct
 * @path: The path to the file
 *
 * Return: 1 if true, 0 otherwise
 */

int is_cmd(info_t *info, char *path)
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
 * dup_chars - It duplicates characters
 * @pathstr: A PATH string
 * @start: The starting index
 * @stop: A stopping index
 *
 * Return: The pointer to new buffer
 */

char *dup_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int x = 0, k = 0;

	for (k = 0, x = start; x < stop; x++)
		if (pathstr[x] != ':')
			buf[k++] = pathstr[x];
	buf[k] = 0;

	return (buf);
}

/**
 * find_path - It finds this cmd in the PATH
 * @info: Info struct
 * @pathstr: A PATH string
 * @cmd: cmd to find
 *
 * Return: full path of cmd if found or NULL
 */

char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int i = 0, curr_pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[i] || pathstr[i] == ':')
		{
			path = dup_chars(pathstr, curr_pos, i);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(info, path))
				return (path);
			if (!pathstr[i])
				break;
			curr_pos = i;
		}
		i++;
	}
	return (NULL);
}

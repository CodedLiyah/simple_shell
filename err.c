#include "shell.h"

/**
 *_eputs - Input string
 * @str: the string to be printed
 *
 * Return: Nothing
 */

void _eputs(char *str)
{
	int x = 0;

	if (!str)
		return;
	while (str[x] != '\0')
	{
		_eputchar(str[x]);
		x++;
	}
}

/**
 * _eputchar - writes character c to stderr
 * @c: Character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _eputchar(char c)
{
	static int x;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || x >= WRITE_BUF_SIZE)
	{
		write(2, buf, x);
		x = 0;
	}
	if (c != BUF_FLUSH)
		buf[x++] = c;
	return (1);
}

/**
 * _putfd - writes the character c to given fd
 * @c: The character to print
 * @fd: The filedescriptor to write to
 *
 * Return: On success 1.
 * On error -1
 */

int _putfd(char c, int fd)
{
	static int x;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || x >= WRITE_BUF_SIZE)
	{
	write(fd, buf, x);
	x = 0;
	}
	if (c != BUF_FLUSH)
		buf[x++] = c;
	return (1);
}

/**
 *_putsfd - An input string
 * @str:String to be printed
 * @fd: A filedescriptor
 *
 * Return: Number of chars
 */

int _putsfd(char *str, int fd)
{
	int x = 0;

	if (!str)
		return (0);
	while (*str)
	{
	x += _putfd(*str++, fd);
	}

	return (x);
}

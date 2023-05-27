#include "shell.h"

/**
 * interactive - Returns true if shell is in interactive mode
 * @info: Is th struct address
 *
 * Return: 1 if shell is in interactive mode, 0 if not
 */

int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - sees if character is a deli
 * @c: the The character to check
 * @delim: Delimeter string
 *
 * Return: 1 if a character is a delim, 0 otherwise
 */

int is_delim(char c, char *delim)
{
	while (*delim)
	if (c == *delim++)
		return (1);
	return (0);
}

/**
 *_isalpha - Looks for alpha character
 *@x: The character to add
 *
 *Return: 1 if the character is alpha, 0 otherwise
 */

int _isalpha(int x)
{
	if ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_atoi - Turns a string into an integer
 *s: the string to be converted
 *
 *Return: 0 on success, converted number otherwise
 */

int _atoi(char *s)
{
	int a, sig = 1, flg = 0, op;
	unsigned int res = 0;

	for (a = 0;  s[a] != '\0' && flg != 2; a++)
	{
		if (s[a] == '-')
			sig *= -1;

		if (s[a] >= '0' && s[a] <= '9')
		{
			flg = 1;
			res *= 10;
			res += (s[a] - '0');
		}

		else if (flg == 1)
			flg = 2;
	}

	if (sig == -1)
		op = -res;
	else
		op = res;

	return (op);
}

#include "shell.h"

/**
 * exitt - Exits the shell
 * @arv: array of words
 *
 */

void exitt(char **arv)
{
	int x, nu;

	if (arv[1])
	{
	nu = _atoi(arv[1]);
	if (nu <= -1)
		nu = 2;
	freearv(arv);
	exit(nu);
	}
	for (x = 0; arv[x]; x++)
		free(arv[x]);
	free(arv);
	exit(0);
}

/**
 * _atoi - Converts a string to an integer
 * @st: pointer to a string
 *
 * Return: Integer
 */

int _atoi(char *st)
{
	int x, y, sig = 1;

	x = 0;
	y = 0;
	while (!((st[x] >= '0') && (st[i] <= '9')) && (st[x] != '\0'))
	{
		if (st[x] == '-')
		{
		sig = sig * (-1);
		}
		x++;
	}
	while ((st[x] >= '0') && (st[x] <= '9'))
	{
	y = (y * 10) + (sig * (st[x] - '0'));
		x++;
	}
	return (y);
}

/**
 * env - Prints current environment
 * @arv: An array of arguments
 */

void env(char **arv __attribute__ ((unused)))
{

	int x;

	for (x = 0; environ[x]; x++)
	{
	_puts(environ[x]);
	_puts("\n");
	}

}

/**
 * _setenv - Initialize a new environment variable
 * @arv: array of inputed words
 */
void _setenv(char **arv)
{
	int x, y, a;

	if (!arv[1] || !arv[2])
	{
	perror(_getenv("_"));
	return;
	}

	for (x = 0; environ[x]; x++)
	{
		y = 0;
		if (arv[1][y] == environ[x][y])
		{
			while (arv[1][y])
			{
				if (arv[1][y] != environ[x][y])
					break;

				y++;
			}
			if (arv[1][y] == '\0')
			{
				a = 0;
				while (arv[2][a])
				{
					environ[x][y + 1 + a] = arv[2][a];
					k++;
				}
				environ[x][y + 1 + a] = '\0';
				return;
			}
		}
	}
	if (!environ[x])
	{

		environ[x] = concat_all(arv[1], "=", arv[2]);
		environ[x + 1] = '\0';

	}
}

/**
 * _unsetenv - Removes a environment variable
 * @arv: array of inputed words
 */

void _unsetenv(char **arv)
{
	int x, y;

	if (!arv[1])
	{
	perror(_getenv("_"));
	return;
	}
	for (x = 0; environ[x]; x++)
	{
		y = 0;
		if (arv[1][y] == environ[x][y])
		{
			while (arv[1][y])
			{
				if (arv[1][y] != environ[i][y])
					break;

				y++;
			}
			if (arv[1][y] == '\0')
			{
				free(environ[x]);
				environ[x] = environ[x + 1];
				while (environ[x])
				{
					environ[x] = environ[x + 1];
					x++;
				}
				return;
			}
		}
	}
}

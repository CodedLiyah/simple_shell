#include "shell.h"

/**
 * sig_handler - Checks whether Ctrl C was pressed
 * @s_num: int
 */
void sig_handler(int s_num)
{
	if (s_num == SIGINT)
	{
	_puts("\n#cisfun$ ");
	}
}

/**
* _EOF - Deals with the end of file
* @l: Return the value of getline function
* @buf: A buffer
*/

void _EOF(int l, char *buf)
{
	(void)buf;

	if (l == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			_puts("\n");
			free(buff);
		}
		exit(0);
	}
}

/**
 * _isatty - Checks terminal
 */

void _isatty(void)
{
	if (isatty(STDIN_FILENO))
	_puts("#cisfun$ ");
}

/**
 * main - A Shell
 *
 * Return: 0 on success
 */

int main(void)
{
	ssize_t l = 0;
	char *buf = NULL, *v, *pn, **arv;
	size_t size = 0;
	list_path *h = NULL;
	void (*f)(char **);

	signal(SIGINT, sig_handler);
	while (l != EOF)
	{
		_isatty();
		l = getline(&buf, &size, stdin);
		_EOF(l, buf);
		arv = splitstring(buf, " \n");
		if (!arv || !arv[0])
			execute(arv);
		else
		{
			v = _getenv("PATH");
			h = linkpath(v);
			pn = _which(arv[0], h);
			f = checkbuild(arv);
			if (f)
			{
				free(buf);
				f(arv);
			}
			else if (!pn)
				execute(arv);
			else if (pn)
			{
				free(arv[0]);
				arv[0] = pn;
				execute(arv);
			}
		}
	}
	free_list(h);
	freearv(arv);
	free(buf);
	return (0);
}

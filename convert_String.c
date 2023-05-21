#include "shell.h"

/**
 * new_interactive - Returns true if shell i in interactive mode
 * @info: Stuct address
 *
 * Return: 1 if in interactive mode, 0 otherwise
 */

int new_interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * check_delim - Checks if characte is a delimiter
 * @dc: The character to check
 * @delim: The delimiter string
 *
 * Return: 1 if true, 0 if false
 */

int check_delim(char dc, char *delim)
{
	while (*delim)
	{
	if (*delim++ == dc)
	return (1)
	}
	return (0);
}

/**
 * is_custom_alpha - Checks for alphabetic character
 * @ca: The character to input
 *
 * Return: 1 if ca is alphabetic, 0 otherwise
 */

int is_custom_alpha(int ca)
{
	if ((ca >= 'a' && ca <= 'z') || (ca >= 'A' && ca <= 'Z'))
	return (1);
	else
	return (0);
}

/**
 * convert_string - Converts a string to an integer
 * @sc: String to be converted
 *
 * Return: 0 if no number, the converted number otherwise
 */

int convert_string(char *sc)
{
	int x, s = 1, f = 0, op;
	unsigned int r = 0;

	for (x = 0; sc[x] != '\0' && f != 2; x++)
	{
		if (sc[x] == '-')
		s *= -1;

	if (sc[x] >= '0' && sc[x] <= '9')
	{
		f = 1;
		r *= 10;
		r += (sc[x] - '0');
	}

	else if (f == 1)
	f = 2;
	}

	if (s == -1)
	op = -r;
	else
	op = r;

	return (op);
}

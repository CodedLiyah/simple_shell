#include "shell.h"

/**
 * _erratoi - Turns a string into an integer
 * @s: String to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 *       -1 on error
 */
int _erratoi(char *s)
{
	int x = 0;
	unsigned long int res = 0;

	if (*s == '+')
		s++;  /* TODO: why does this make main return 255? */
	for (x = 0;  s[x] != '\0'; x++)
	{
		if (s[x] >= '0' && s[x] <= '9')
		{
			res *= 10;
			res += (s[x] - '0');
			if (res > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (res);
}

/**
 * print_error - An error message
 * @info: Parameter return info struct
 * @estr: A string contains specified error
 *
 * Return: 0 if no numbers in string, converted number otherwise
 *        -1 on error
 */

void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * print_d - Function prints a decimal
 * @input: Input
 * @fd: Filedescriptor to write
 *
 * Return: number of characters printed
 */

int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int x, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (x = 1000000000; x > 1; x /= 10)
	{
		if (_abs_ / x)
		{
			__putchar('0' + current / x);
			count++;
		}
		current %= x;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/**
 * convert_number - A clone of itoa
 * @num: A number
 * @base: A base
 * @flags: Flags
 *
 * Return: A string
 */

char *convert_number(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;

	return (ptr);
}

/**
 * remove_comments - Replaces first instance of '#' with '\0'
 * @buf: Location of the string to edit
 *
 * Return: Always 0;
 */

void remove_comments(char *buf)
{
	int x;

	for (x = 0; buf[x] != '\0'; x++)
		if (buf[x] == '#' && (!x || buf[x - 1] == ' '))
		{
			buf[x] = '\0';
			break;
		}
}

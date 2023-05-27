#include "shell.h"

/**
 **_strncpy - Copies string
 *@dest: Destination string to be copied to
 *@src: Source string
 *@n: Amount of chars to be copied
 *Return: Concatenated string
 */

char *_strncpy(char *dest, char *src, int n)
{
	int x, y;
	char *s = dest;

	x = 0;
	while (src[y] != '\0' && x < n - 1)
	{
	dest[x] = src[x];
	x++;
	}

	if (x < n)
	{
		y = x;
		while (y < n)
		{
		dest[y] = '\0';
		y++;
		}
	}
	return (s);
}

/**
 **_strncat - This concatenates two strings
 *@dest: First string
 *@src: Second string
 *@n: Amount of bytes to be used
 *
 *Return: Concatenated string
 */

char *_strncat(char *dest, char *src, int n)
{
	int x, y;
	char *s = dest;

	x = 0;
	y = 0;
	while (dest[x] != '\0')
		x++;
	while (src[y] != '\0' && y < n)
	{
		dest[x] = src[y];
		x++;
		y++;
	}

	if (y < n)
		dest[x] = '\0';
	return (s);
}

/**
 **_strchr - locates a character in a string
 *@s: the string to be parsed
 *@c: the character to look for
 *Return: (s) a pointer to the memory area s
 */

char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}

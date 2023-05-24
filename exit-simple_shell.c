#include "shell.h"

/**
 **_strncpy - copies a string to another
 *@loca: the location  string to be copied to
 *@src: the source string
 *@n: the amount of characters to be copied
 *Return: the concatenated string
 */
char *_strncpy(char *loca, char *src, int n)
{
	int a, j;
	char *s = loca;

	a = 0;
	while (src[a] != '\0' && a < n - 1)
	{
		loca[a] = src[a];
		a++;
	}
	if (a < n)
	{
		j = a;
		while (j < n)
		{
			loca[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 **_strncat - links two strings
 *@loca: This is pointer to the destination array
 *@src: string to appended
 *@n: This is the maximum number of characters to be appended.
 *Return: returns a pointer to the resulting string destination
 */
char *_strncat(char *loca, char *src, int n)
{
	int a, j;
	char *s = loca;

	a = 0;
	j = 0;
	while (loca[a] != '\0')
		a++;
	while (src[j] != '\0' && j < n)
	{
		loca[a] = src[j];
		a++;
		j++;
	}
	if (j < n)
		loca[a] = '\0';
	return (s);
}

/**
 **_strchr - searches for the first occurrence of the character
 *@str: the string to be scanned
 *@c: the character to be searched for
 *Return: first character, or NULL if the character is not found.
 */
char *_strchr(char *str, char c)
{
	do {
		if (*str == c)
			return (str);
	} while (*str++ != '\0');

	return (NULL);
}

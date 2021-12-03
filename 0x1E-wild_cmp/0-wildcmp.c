#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * wildcmp - compares two strings.
 * @s1: string to compare
 * @s2: string to compare.
 * Return: 1 otherwise return 0.
*/

int wildcmp(char *s1, char *s2)
{
	if (!*s1)
	{
		if (*s2 == '*')
			return (wildcmp(s1, s2 + 1));
		return (*s2 == '\0');
	}
	if (*s2 == '*')
		return (wildcmp(s1, s2 + 1) || wildcmp(s1 + 1, s2));
	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));
	return (0);
}

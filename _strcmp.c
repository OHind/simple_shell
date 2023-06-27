#include "main.h"
/**
 * _strcmp - compares two strings
 * @s1: First string
 * @s2: Second string
 * Return: 0 if the strings are equal, the difference otherwise
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; *(s1 + i) != '\0' && *(s2 + i) != '\0'; i++)
	{
		if (*(s1 + i) < *(s2 + i))
			return (*(s1 + i) - *(s2 + i));
		else if (*(s1 + i) > *(s2 + i))
			return (*(s1 + i) - *(s2 - i));
	}
	return (0);
}

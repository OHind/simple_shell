#include "main.h"
/**
 * _strlen - returns the length of a given string
 * @c: the input string
 * Return: the length of a given string
 */
int _strlen(char *c)
{
	int i = 0;

	while (*(c + i) != '\0')
	{
		i++;
	}
	return (i);
}

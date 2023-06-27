#include "main.h"
/**
 * _strdup - duplicate a given pointer to a newely allocated memory
 * @s: string to duplicate
 * Return: pointer to a newly allocated memory
 */
char *_strdup(char *s)
{
	int l = 0, i = 0;
	char *ar;

	if (s == NULL)
	{
		return (NULL);
	}
	l = _strlen(s);
	ar = malloc(sizeof(char) * (l + 1));
	for (i = 0; i < l; i++)
	{
		*(ar + i) = *(s + i);
	}
	*(ar + i) = '\0';
	return (ar);
}

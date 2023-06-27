#include "main.h"
/**
 * free_array - free an array
 * @a: array to be freed
 * Return: void
 */
void free_array(char **a)
{
	size_t i;

	for (i = 0; **(a + i) != '\0'; i++)
		free(*(a + i));
	free(a);
}

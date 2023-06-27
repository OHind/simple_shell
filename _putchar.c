#include "main.h"
/**
 * _putchar - prints a caracter into teh stdout
 * @c: tThe caracter to print
 * Return: 1 id opertaion succeeded, -1 otherwise
 */
int _putchar(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}

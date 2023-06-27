#include "main.h"
/**
 * print_number - print a number
 * @n: The number to print
 * Return: void
 */
void print_number(int n)
{
	int d, sum = 0, l;
	unsigned int num = n;
	int divis = 1000000000;

	while (divis > 1)
	{
		d = (num / divis) % 10;
		sum += d;
		if(sum != 0)
			_putchar(d + '0');
		divis = divis / 10;
	}
	l = num % 10;
	_putchar(l + '0');
}

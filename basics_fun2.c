#include "main.h"

/**
 *_allocat_loc -allocated memoria for nmeb elemn de zise bytes
 *@nm: number of element in the array
 *@s: bytes for each position in the array
 *Return: pointer void
 */


void *_allocat_loc(unsigned int nm, unsigned int s)
{
	char *p;
	unsigned int i;

	if (nm == 0 || s == 0)
		return (NULL);

	p = malloc(nm * s);
	if (p == NULL)
		return (NULL);

	for (i = 0; i < nm * s; i++)
		p[i] = 0;

	return (p);

}

/**
 * _int_to_ascii - converts an integer to ASCII
 * @num: number
 * @base: base
 * reference: geeksforgeeks
 * Return: character string
 **/
char *_int_to_ascii(int num, int base)
{
	static char *d = "0123456789abcdef";
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = (unsigned long)num;

	if (num < 0)
	{
		n = (unsigned long)(-num);
		sign = '-';
	}

	ptr = &buffer[49];
	*ptr = '\0';
	do {
		*--ptr = d[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;

	return (ptr);
}


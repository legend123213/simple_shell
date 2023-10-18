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
 *_put_str - prints a strings
 *@s: A to be printed
 *
 *Return: void
 */
void _put_str(char *s)
{
	int i;

	for (i = 0 ; s[i] != '\0' ; i++)
	{
		_putchar(s[i]);
	}
	_putchar('\n');
}

/**
 * search - gets the path to execute commands
 * @env_var: Environment variable
 * Return: kalat_path (array of directories containing the command)
 *	or NULL on failure
 **/
char **search(char **env_var)
{
	int position = 0;
	char **kalat_path;

	for (; environ[position] != NULL ; position++)
	{
		if (environ[position][0] == 'P' && environ[position][2] == 'T')
		{
			kalat_path = _which(env_var[position]);
		}
	}
	return (kalat_path);
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

/**
 * str_concatenate - concatenate two strings
 * @s_one: first string
 * @s_two: second string
 *
 * Return: pointer to the concatenated string
 */
char *str_concatenate(char *s_one, char *s_two)
{
	char *dest;
	unsigned int i, j, size;

	/* If the array is empty */
	if (s_one == NULL)
		s_one = "";

	if (s_two == NULL)
		s_two = "";
	/* Count total size */

	size = (_str_length(s) + _str_length(s_two) + 1);

	/* Allocate memory */

	dest = (char *) malloc(size * sizeof(char));

	if (dest == 0)
	{
		return (NULL);
	}

	/* Concatenate arrays */
	for (i = 0; *(s_one + i) != '\0'; i++)
		*(dest + i) = *(s_one + i);

	for (j = 0; *(s_two + j) != '\0'; j++)
	{
		*(dest + i) = *(s_two + j);
		i++;

	}
	dest[i] = '\0';
	return (dest);

}


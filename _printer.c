#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @C: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char C)
{
	return (write(1, &C, 1));
}



/**
 * prints - Prints a string
 * @str: Pointer to the string to print
 *
 * Return: void
 */
void prints(char *str)
{
	int i = 0;

	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
}


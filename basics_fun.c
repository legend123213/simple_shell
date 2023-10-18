#include "main.h"

/**
 * _str_length - returns a string
 * @S: integer to be used
 * Return: length of string
 */
int _str_length(const char *S)
{
	int k;

	k = 0;
	while (S[k] != '\0')
	{
		k++;
	}
	return ((k + 1));
}


/**
 * *_memory_copy - copies bytes from source to destination
 *
 * @des: memory to be transfer to
 * @source: memory to be transfer from
 * @n: number of bytes to be transfered
 * Return:dest
 */
char *_memory_copy(char *des, char *source, unsigned int n)
{
	int i;

	for (i = 0; n > 0; i++)
	{
		des[i] = source[i];
		n--;
	}

	return (des);
}

/**
 * _str_compare - this compares two strings
 * @s_one: first string
 * @s_two: second string
 * Return: integer
 */

int _str_compare(char *s_one, char *s_two)
{
	int s;

	s = 0;
	while (s_one[s] != '\0' && s_two[s] != '\0')
	{
		if (s_one[s] != s_two[s])
			return (s_one[s] - s_two[s]);

		s++;
	}

	return (0);
}


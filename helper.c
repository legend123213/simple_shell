#include "main.h"

/**
 * *_str_copy - copies a string pointed to by src to dest
 * @source: variale where string will be copied from
 * @des: variable that string will be copied to
 * Return: des
 */
char *_str_copy(char *des, char *source)
{
	int a;

	for (a = 0; source[a] != '\0'; a++)
	{
		des[a] = source[a];
	}
	des[a] = '\0';

	return (des);
}

/**
 * _str_dup - copies the string and it returns their pointer
 *
 * @s: string to be copied
 * Return: String
 */

char *_str_dup(char *s)
{
	char *dup;
	unsigned int i, counter;

	i = 0;
	counter = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		i++;
		counter++;
	}
	counter++;
	dup = malloc(sizeof(char) * counter);
	if (dup == NULL)
		return (NULL);
	for (i = 0; i < sizeof(char) * counter; i++)
		dup[i] = s[i];

	return (dup);
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

	size = (_str_length(s_one) + _str_length(s_two) + 1);

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
			kalat_path =_path_chooser(env_var[position]);
		}
	}
	return (kalat_path);
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

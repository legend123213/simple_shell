#include "main.h"

/**
 *pri_prompt - prints prompt
 * Return: void
 */
void pri_prompt(void)
{
	char *buffer = getcwd(NULL, 0);

	if (isatty(STDIN_FILENO))
		prints("$ ");
	free(buffer);
}


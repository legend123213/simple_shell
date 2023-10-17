#include "main.h"

/**
 * handle_signal - handles EOF signal
 * @signal: EOF indicator
 * Return: void
 */

void handle_signal(int signal)
{
	(void) signal;
	prints("\n$ ");
	fflush(stdout);
}

/**
 * _error - prints the error output of a file
 * @argv: name of program
 * @count: number of prompt
 * @args: command to be put in
 * Return: 0 on success
 */
int *_error(char *argv, int count, char *args)
{
	char *number;

	number = _int_to_ascii(count, 10);

	write(2, argv, _str_length(argv));
	write(2, ": ", 2);
	write(2, number, _str_length(number));
	write(2, ": ", 2);
	write(2, args, _str_length(args));
	perror(" ");

	return (0);
}

/**
 * _sta - get file status
 * @cmd: array of commands
 * @aketacha: array of directory paths
 * Return: 1 on success
 **/
int _sta(char **cmd, char **aketacha)
{
	char *concat_str = NULL, *new_concat = NULL;
	int mekutriya;
	struct stat sb;

	if (aketacha == NULL)
	{
		free(aketacha);
		free(cmd);
		return (0);
	}
	for (mekutriya = 0; aketacha[mekutriya] != NULL ; mekutriya++)
	{
		concat_str = str_concatenate(aketacha[mekutriya], "/");
		new_concat = str_concatenate(concat_str, cmd[0]);

		if (stat(new_concat, &sb) == 0 && (sb.st_mode & S_IXUSR))
		{
			cmd[0] = new_concat;
			free(concat_str);
			free(aketacha[0]);
			free(aketacha);
			return (1);
		}

		free(concat_str);
		free(new_concat);
	}
	free(aketacha[0]);
	free(aketacha);
	return (0);
}


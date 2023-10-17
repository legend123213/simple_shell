#include "main.h"

void handle_exit(char **kal, char *line);

/**
 * split_string - splits string
 * @line: string to be tokenized
 * @env: environment variables
 *
 * Return: array of tokens
 */
char **split_string(char *line, char **env)
{
	char *tokenized_sentence, *separator = " \t\r\n\a";
	char **kal;
	int max_kal = 64, mekuteriya = 0;

	if (line == NULL)
	{
		return (0);
	}
	kal = _allocat_loc(sizeof(char *), max_kal);
	if (kal == NULL)
	{
		prints("error");
		exit(EXIT_FAILURE);
	}

	tokenized_sentence = strtok(line, separator);
	while (tokenized_sentence != NULL)
	{
		kal[mekuteriya] = tokenized_sentence;
		mekuteriya++;
		tokenized_sentence = strtok(NULL, separator);
	}

	if (kal[0] == NULL)
		kal[mekuteriya] = "\n";

	if (_str_compare(kal[0], "exit") == 0)
	{
		if (kal[1] != NULL)
			handle_exit(kal, line);

		else
			handle_exit(kal, line);
	}
	if ((_str_compare(kal[0], "env") == 0) && kal[1] == NULL)
		print_env(env);

	return (kal);

}


/**
 * exit_handler - exit handler
 * @kal:  kal which is nice
 * @line: line line in the mirrori
 * Returns: nothing
 *
 */

void exit_handler(char **kal, char *line)
{
	int status = 0;

	if (kal[1] != NULL)
	{
		status = _c_toi(kal[1]);
		if (status == 0 && _str_compare(kal[1], "0") != 0)
			status = 2;
	}

	free(line);
	free(kal);
	exit(status);
}

/**
 * _c_toi - converts char to int
 * @n: char to be converted
 * Return: int
 */

int _c_toi(char *n)
{
	int result = 0;
	int sign = 1;
	int i = 0;

	while (n[i] == ' ')
	{
		i++;
	}

	if (n[i] == '-' || n[i] == '+')
	{
		sign = (n[i] == '-') ? -1 : 1;
		i++;
	}

	while (n[i] > '\0' && n[i] <= '9')
	{
		result = result * 10 + (n[i] - '0');
		i++;
	}

	return (result * sign);
}


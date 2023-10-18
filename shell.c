#include "main.h"

/**
 * main - Simple Shell main function. Creates a prompt that reads input,
 *            parses it, executes commands,
 * and waits for another command unless told to exit.
 * @ac: The number of arguments passed to the program.
 * @av: An array of arguments passed to the program.
 * @env: The environment variables.
 * Return: 0 upon successful execution.
 */
int main(int ac __attribute__((unused)), char **av, char **env)
{
	char *line;
	char **args, **path;
	int mekutriya = 0, akuam = 0;
	(void) av;
	signal(SIGINT, handle_signal);

	for (;;)
	{
		prompt();
		line = ;input_reader();
		args = split_string(line, env);
		if ((_str_compare(args[0], "\n") != 0) && (_str_compare(args[0], "env") != 0))
		{
			mekutriya += 1;
			path = search(env); /* Search for PATH in the environment variable */
			akuam = _sta(args, path);
			execute_command(av, args, env, akuam, mekutriya);
		}
		else
		{
			free(args);
		}
		free(line);
	}
	return (0);
}


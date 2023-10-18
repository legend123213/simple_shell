#include "main.h"

/**
 * execute_command - executes a command as a child process
 * @av: array of arguments
 * @args: array of parsed arguments
 * @env_var: environment variables
 * @status: status of the main function
 * @counter: command count
 *
 * Return: 1 on success
 */

int execute_command(char **av, char **args,
	char **env_var, int status, int counter)
{
	pid_t pid;
	int status;

	if (args == NULL)
		return (-1);

	pid = fork();
	if (pid  < 0)
	{
		perror("./hsh: ");
		exit(1);
	}
	else if (pid == 0)
	{
		if (execve(args[0], args, env) == -1)
		{
			_error(av[0], counter, args[0]);
			free(args);
			exit(1);
		}
		exit(0);
	}
	else
	{
		if (status == 1)
			free(args[0]);

		free(args);
		waitpid(pid, &status, WUNTRACED);
	}
	return (1);
}


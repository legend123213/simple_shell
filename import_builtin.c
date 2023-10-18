#include "main.h"

/**
 * print_env - prints the current environment
 * @env_var: environment variable
 */
void print_env(char **env_var)
{
	int i = 0;

	for (; env_var[i] ; i++)
		_put_str(env_var[i]);
}


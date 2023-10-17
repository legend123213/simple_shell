#include "main.h"

/**
 * _path_chooser - identifies the path of the command (cmd)
 * that is being passed to it
 * @cmd: the command that is being passed to it
 *
 * Return: an array of directories containing the command or NULL on failure
 */
char **_path_chooser(char *cmd)
{
	int size = 64;
	int i = 0;
	char *copy_path = NULL;
	char *delimiter = ":=";

	char **dirs = _allocat_loc(sizeof(char *), size);
	char *token = NULL;

	if (cmd == NULL)
	{
		free(cmd);
		return (0);
	}
	if (dirs == NULL)
	{
		free(cmd);
		perror("Error allocated memory");
		return (NULL);
	}
	copy_path = _str_dup(cmd); /* Copy the cmd string */
	token = strtok(copy_path, delimiter); /* Split the string by the delimiter */

	while (token != NULL)
	{
		dirs[i] = token;
		i++;
		token = strtok(NULL, delimiter);
	}
	return (dirs);
}


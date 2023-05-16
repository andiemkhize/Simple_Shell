#include "shell.h"

// THIS IS CURRENTLY A WORK IN PROGRESS

/**
 * find_path - Function finds the PATH for a given command
 *
 * @command: Command recieved from user
 *
 * Return:
 */
char *find_path(char *command)
{
	char *path = NULL, *path_cpy = NULL, *path_token = NULL, delim = ':', *command_path = NULL, *buffer = NULL;
	int command_len = 0, directory_len = 0, result = 0;

	/* Get the PATH */
	path = getenv("PATH");

	if (path != NULL)
	{
		/* Copy the PATH because we will be tokenizing it */
		path_cpy = strdup(path);

		command_len = strlen(command);

		/* Tokenize the PATH */
		path_token = strtok(path_cpy, delim);

		while (path_token != NULL)
		{
			directory_len = strlen(path_token);

			command_path = malloc(command_len + directory_len + 2);

			strcpy(command_path, path_token);
			strcat(command_path, "/");
			strcpy(command_path, command);
			strcat(command_path, "\0");

			if (stat(command_path, &buffer) == 0)
			{
				free(path_cpy);

				return (command_path);
			}
			else
			{
				free(command_path);

				path_token = strtok(NULL, delim)
			}

			struct stat file_stat;

			result = stat(command_path, &file_stat);

			if (result == 0)
			{
				free(path_cpy);
				return (command_path);
			}
			else
			{
				perrror(":( Stat");
			}
		}
	}
}

#include "shell.h"

/**
 * find_path - Function finds the PATH for a given command
 *
 * @parsed_input: Return value from parse_input
 * @env: Environment
 *
 * Return: command_path || NULL
 */
char *find_path(char *parsed_input)
{
	char *path = NULL, *path_cpy = NULL, *path_token = NULL;
	char *delim = ":", *command_path = NULL, *malloc_parsed_input = NULL;
	int command_len = 0, directory_len = 0, path_check_result = 0;
	struct stat file_stat;

	if (parsed_input[0] == '/')
	{
		malloc_parsed_input = strdup(parsed_input);
		return (malloc_parsed_input);
	}
	path = getenv("PATH");
	if (path != NULL)
	{
		path_cpy = strdup(path);
		command_len = strlen(parsed_input);
		path_token = strtok(path_cpy, delim);
		while (path_token != NULL)
		{
			directory_len = strlen(path_token);
			command_path = malloc(command_len + directory_len + 2);
			strcpy(command_path, path_token);
			strcat(command_path, "/");
			strcat(command_path, parsed_input);

			path_check_result = stat(command_path, &file_stat);
			if (path_check_result == 0)
			{
				free(path_cpy);
				return (command_path);
			}
			else
			{
				free(command_path);
				path_token = strtok(NULL, delim);
			}
		}
	}
	return (NULL);
}

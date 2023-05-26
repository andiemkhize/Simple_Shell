#include "shell.h"

/**
 * file_exists - Function checks if file exists in the path
 * @path: PATH
 * Return: a bool value
 */
int file_exists(char *path)
{
	return (access(path, F_OK) != -1);
}

/**
 * find_command_execute - Function looks for the command and executes
 * @tokens: Array of tokens
 * @env: Environment variables
 */
void find_command_execute(char **tokens, char **env)
{
	char *command = tokens[0];
	char *path = getenv("PATH");
	char *path_cpy = strdup(path);
	char *path_token;
	char *absolute_path = malloc(MAX_INPUT_SIZE * sizeof(char));

	if (file_exists(command))
	{

		execve(command, tokens, env);
		perror("execve() failed");
		exit(EXIT_FAILURE);
	}
	else
	{
		path_token = strtok(path_cpy, TOKEN_DELIM);
		while (path_token != NULL)
		{
			strcpy(absolute_path, path_token);
			strcat(absolute_path, "/");
			strcat(absolute_path, command);
			if (file_exists(absolute_path))
			{
				free(path_cpy);
				execve(absolute_path, tokens, env);
				perror("execve() failed");
				exit(EXIT_FAILURE);
			}
			path_token = strtok(NULL, TOKEN_DELIM);
		}

		free(path_cpy);

		perror(command);
		exit(EXIT_FAILURE);
	}
}

/**
 * execute_command - Function executes the command for the child process
 * @tokens: Array of tokens
 * @env: Environment variables
 */
void execute_command(char **tokens, char **env)
{
	pid_t fork_result = fork();
	int status;

	if (fork_result == 0)
	{
		find_command_execute(tokens, env);
		free_tokens(tokens);
		exit(EXIT_SUCCESS);
	}
	else if (fork_result < 0)
	{
		perror("fork() failed");
	}
	else
	{
		waitpid(fork_result, &status, 0);
	}
}

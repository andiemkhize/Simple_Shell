#include "shell.h"

/**
 * execute_command - Function executes the command
 *
 * @argv: Argument vector
 * @command: Command parsed by the user to be executed
 * @env: Environment variables
 *
 * Return: Void
 */
void execute_command(char **argv, char *command, char **env)
{
	int execve_result, status;
	pid_t fork_result;

	if (command != NULL)
	{
		if (access(command, X_OK) != -1)
		{
			fork_result = fork();

			if (fork_result == -1)
			{
				perror("$ fork() failed");
			}
			else if (fork_result == 0)
			{
				execve_result = execve(command, argv, env);

				if (execve_result == -1)
				{
					free(command);
					perror("$ execve() failed");
					exit(EXIT_FAILURE);
				}
			}
			else
			{
				waitpid(fork_result, &status, 0);
			}
		}
		else
		{
			perror(command);
		}
	}
	else
	{
		command = argv[0];
		perror(command);
	}
}

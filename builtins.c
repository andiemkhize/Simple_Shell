#include "shell.h"

/**
 * exit_builtin - Function exits the shell
 * @env: Environment
 */
void exit_builtin(char **env)
{
	(void)env;

	exit(EXIT_SUCCESS);
}

/**
 * printenv_builtin - Function prints out each environment variable
 * @env: Environment
 */
void printenv_builtin(char **env)
{
	size_t len;
	ssize_t char_written;

	if (env == NULL)
	{
		perror("$ Invalid environment");
		exit(EXIT_FAILURE);
	}

	printf("%s\n", *env);

	while (*env != NULL)
	{
		len = strlen(*env);
		char_written = write(STDOUT_FILENO, *env, len);
		write(STDOUT_FILENO, "\n", 1);

		if (char_written == -1)
		{
			perror("$ Env write error");
			exit(EXIT_FAILURE);
		}
		env++;
	}
}

/**
 * print_prompt - Function prints the symbol indicating the prompt
 */
void print_prompt(void)
{
		write(STDOUT_FILENO, ANSI_COLOR_GREEN "$ " ANSI_COLOR_RESET, 12);
}

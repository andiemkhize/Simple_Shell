#include "shell.h"

/**
 * exit - handles the exit built-in command
 * @exit_args: the exit command arguments
 * @nargs: the number of arguments passed
 *
 * Return: Nothing
 */

void exit(char **exit_args, size_t nargs)
{
	int status = EXIT_SUCCESS;

	if (exit_args[1])
		status = _atoi(exit_args[1]);

	free_vector(exit_args, nargs);
	exit(status);
}

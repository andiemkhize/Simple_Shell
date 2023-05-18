#include "shell"

/**
 * env - handles the env built in command
 * @env_args: the env command arguments
 * @nargs: the number of arguements passed
 *
 * Return: Nothing
 */

void env(char **env_args, size_t nargs)
{
	if (!env_args[1])
		_printenv();

	free_vector(env_args, nargs)
}

/**
 * _printenv - prints the environment variable
 *
 * Return: Nothing
 */

void _printenv(void)
{
	int var;

	for (var = 0; environ[var]; var++)
		printf("%s\n, environ[var]);
}

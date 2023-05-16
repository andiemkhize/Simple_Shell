#include "shell.h"

void execute_command(char **argv)
{
	char *command = NULL;

	if (argv != NULL)
	{
		command = argv[0];

		if (execve(command, argv, NULL) == -1)
		{
			perror(":( Error");
		}
	}
}

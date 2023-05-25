#include "shell.h"

/*
 * This file contains all the functions needed for the Simple Shell to work
 */

/**
 * read_input - Function reads input from stdin
 *
 * Return: Returns input
 */
char *read_input(void)
{
	char *input = NULL;
	size_t len = 0;
	ssize_t char_read;

	char_read = getline(&input, &len, stdin);

	if (char_read == -1)
	{
		if (feof(stdin))
		{
			exit(EXIT_SUCCESS);
		}
		else if (ferror(stdin))
		{
			perror("$ getline() Error");
			exit(EXIT_FAILURE);
		}
	}

	if (char_read == 1 && input[0] == '\n')
	{
		free(input);
		return (NULL);
	}
	return (input);
}

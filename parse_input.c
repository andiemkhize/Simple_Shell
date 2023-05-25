#include "shell.h"

/**
 * parse_input - Function tokenizes the input
 *
 * @str: String to be tokenized
 * @argv: Argument vector
 * @argc: Argument count
 *
 * Return: argv (An array of tokens)
 */
char **parse_input(char *str, char **argv, int argc)
{
	char *str_cpy = NULL, *token = NULL;
	const char *delim = " \n";
	int i = 0;

	str_cpy = malloc(sizeof(char) * (strlen(str) + 1));
	if (str_cpy == NULL)
	{
		perror("$ malloc for str_cpy failed");
		exit(EXIT_FAILURE);
	}

	strcpy(str_cpy, str);

	token = strtok(str, delim);
	argc = 0;

	while (token != NULL)
	{
		argc++;
		token = strtok(NULL, delim);
	}

	argv = malloc(sizeof(char *) * (argc + 1));
	if (argv == NULL)
	{
		perror("$ malloc for agrv failed");
		exit(EXIT_FAILURE);
	}
	token = strtok(str_cpy, delim);

	while (token != NULL)
	{
		argv[i] = malloc(sizeof(char) * (strlen(token) + 1));
		argv[i] = token;
		token = strtok(NULL, delim);
		i++;
	}
	argv[i] = NULL;

	return (argv);
}

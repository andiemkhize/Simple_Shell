#include "shell.h"

/**
 * read_input - Function reads input from stdin
 *
 * return: Returns the input
 */
char *read_input(void)
{
	char *input = NULL;
	size_t len = 0;
	ssize_t char_read;

	/* Getting the input/command from user */
	printf(":) ");
	char_read = getline(&input, &len, stdin);

	if (char_read == -1)
	{
		printf("Leaving Shell.. Bye!\n"); /* Test using CTRL + D */
		exit(EXIT_SUCCESS);
	}

	return (input);
}
/**
 * parse_input - Function tokenizes the input
 *
 * @str: String to be tokenized
 *
 * Return: argv (An array of tokens)
 */
char **parse_input(char *str, char **argv, int argc)
{
	char *str_cpy = NULL, *token = NULL;
	const char *delim = " \n";
	int i = 0;

	/* Make a copy of input to use for second tokenization */
	str_cpy = strdup(str);

	if (str_cpy == NULL)
	{
		perror("ssh: Memory Allocation Error");
		exit(EXIT_SUCCESS);
	}

	/* Convert input into tokens */
	token = strtok(str, delim);

	argc = 0;

	while (token != NULL)
	{
		argc++;
		token = strtok(NULL, delim);
	}

	// printf("Number of tokens: %d\n", argc);

	argv = malloc(sizeof(char *) * argc);

	token = strtok(str_cpy, delim);

	while (token != NULL)
	{
		argv[i] = strdup(token);
		token = strtok(NULL, delim);
		i++;
	}
	argv[i] = NULL;

	i = 0;

	/* Find out if the tokens are counted and stored correctly */
	// while (i < argc)
	// {
	// 	printf("Token[%d]: %s\n", i, argv[i]);
	// 	i++;
	// }

	return (argv);
}

int main(int argc, char **argv)
{
	char *user_input, **parsed_input;

	printf("===== Welcome to the Simple Shell =====\n\n");
	while (true)
	{
		user_input = read_input();
		parsed_input = parse_input(user_input, argv, argc);

		execute_command(parsed_input);
		// printf("%s\n", user_input); /* Check if user input is being recieved and stored */
	}

	return (0);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

/**
 * read_input - Function reads input from stdin
 *
 * return: Returns the input
 */
char *read_input(void)
{
	char *input = NULL;
	size_t len = 0;
	int char_read;

	/* Getting the input/command from user */
	char_read = getline(&input, &len, stdin);

	if (char_read == -1)
	{
		perror("Error reading line");
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
char **parse_input(char *str)
{
	char *str_cpy = NULL, *token = NULL, *delim = " \n", **argv = NULL, *shut_down = "exit";
	int argc = 0;

	/* Exit the shell if "exit" is entered */
	if (strcmp(str, shut_down) == 0)
	{
		printf("Shutting down Simple Shell.. Bye!\n");
		exit(EXIT_FAILURE);
	}

	/* Make a copy of input to use for second tokenization */
	str_cpy = strdup(str);

	/* Convert input into tokens */
	token = strtok(str, delim);
	int i = 0;

	/* Find out the number of tokens in argument */
	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, delim);
		argc++;
	}
	// printf("\nThere were %d tokens in your input\n", argc); /* Find out if argc is counting the tokens correctly */

	token = strtok(str_cpy, delim);
	argv = malloc(sizeof(char *) * argc);

	while (token != NULL)
	{
		argv[i] = strdup(token);
		// printf("argv[%d]: %s\n", i, argv[i]); /* Find out if each token as been assigned correctly */
		token = strtok(NULL, delim);
		i++;
	}
	argv[i] = NULL;

	free(str_cpy);

	// printf("%s", *argv);

	return (argv);
}

/**
 * interpret_input - Function seearches for command
 * @
 * Return:
 */
// interpret_input(parsed_input)
// {

// }

/**
 * main - Entry point
 *
 * Return: 0 (Sucess)
 */

int main(void)
{
	char *user_input, **parsed_input;

	printf("===== Welcome to the Simple Shell =====\n\n");
	while (true)
	{
		printf(":) ");
		user_input = read_input();
		parsed_input = parse_input(user_input);
		// action = interpret_input(parsed_input);
		// execute_action(action);

		/* Used to check if the tokens where being parsed correctly */
		// int i;

		// while (parsed_input[i] != 0)
		// {
		// 	printf("Token %d is: %s\n", i, parsed_input[i]);
		// 	i++;
		// }

		free(user_input);
		free(parsed_input);
	}

	return (0);
}
#include "shell.h"

/**
 * tokenize_input - Function tokenizes the input from the user
 * @input: Input received from the user
 * Return: tokens
 */
char **tokenize_input(char *input)
{
	int i = 0;
	char **tokens = malloc(MAX_TOKENS * sizeof(char *));
	char *token = strtok(input, TOKEN_DELIM);

	while (token != NULL)
	{
		tokens[i] = strdup(token);
		i++;
		token = strtok(NULL, TOKEN_DELIM);
	}
	tokens[i] = NULL;
	return (tokens);
}

/**
 * free_tokens - Function frees tokens stored in tokens
 * @tokens: Array of tokens
 */
void free_tokens(char **tokens)
{
	int i;

	if (tokens == NULL)
	{
		return;
	}

	for (i = 0; tokens[i] != NULL; i++)
	{
		free(tokens[i]);
		tokens[i] = NULL;
	}
	free(tokens);
}

/**
 * main - Entry point
 *
 * @argc: Argument count
 * @argv: Argument vector
 * @env: Environment varibles
 *
 * Return: 0 (Sucess)
 */
int main(int argc, char **argv, char **env)
{
	char *input = NULL;
	size_t input_size = 0;
	char **tokens;
	(void)argc;
	(void)argv;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("$ ");
			fflush(stdout);
		}

		if (getline(&input, &input_size, stdin) == -1)
		{
			break;
		}

		tokens = tokenize_input(input);
		if (tokens[0] == NULL)
		{
			free_tokens(tokens);
			continue;
		}

		if (strcmp(tokens[0], "exit") == 0)
		{
			free(input);
			exit(EXIT_SUCCESS);
		}

		execute_command(tokens, env);
		free_tokens(tokens);
	}
	free(input);

	return (0);
}

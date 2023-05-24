#include "shell.h"

/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Argument vector
 * @env: Environment
 *
 * Return: 0 (Sucess)
 */
int main(int argc, char **argv, char **env)
{
	builtin command_action[] = {
	    {"exit\n", exit_builtin},
	    {"env\n", printenv_builtin},
	};

	char *user_input, **parsed_input, *command;
	int num_builtins, i;

	num_builtins = sizeof(command_action) / sizeof(builtin);

	while (true)
	{
		if (isatty(STDIN_FILENO))
		{
			print_prompt();
		}

		user_input = read_input();

		if (user_input == NULL)
		{
			continue;
		}

		for (i = 0; i < num_builtins; i++)
		{
			if (_strcmp(user_input, command_action[i].name) == 0)
			{
				command_action[i].function(env);
				break;
			}
		}

		parsed_input = parse_input(user_input, argv, argc);
		command = find_path(*parsed_input, env);
		execute_command(parsed_input, command);

		free(user_input);
		free(parsed_input);
		free(command);
	}

	return (0);
}

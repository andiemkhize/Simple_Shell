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

        write(STDOUT_FILENO, "$ ", 2);

        char_read = getline(&input, &len, stdin);

        if (char_read == -1)
        {
                if (feof(stdin))
                {
                        write(STDOUT_FILENO, "Leaving Shell.. Bye!\n", 21);
                        exit(EXIT_SUCCESS);
                }
                else if (ferror(stdin))
                {
                        perror("$ Getline Error");
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

        str_cpy = strdup(str);

        if (str_cpy == NULL)
        {
                perror("$ str_cpy() failed)");
                exit(EXIT_SUCCESS);
        }

        token = strtok(str, delim);
        argc = 0;

        while (token != NULL)
        {
                argc++;
                token = strtok(NULL, delim);
        }

        argv = malloc(sizeof(char *) * argc);
        token = strtok(str_cpy, delim);

        while (token != NULL)
        {
                argv[i] = strdup(token);
                token = strtok(NULL, delim);
                i++;
        }
        argv[i] = NULL;

        return (argv);
}

/**
 * find_path - Function finds the PATH for a given command
 *
 * @parsed_input: Return value from parse_input
 *
 * Return: command_path || NULL
 */
char *find_path(char *parsed_input)
{
        char *path = NULL, *path_cpy = NULL, *path_token = NULL;
        char *delim = ":", *command_path = NULL, *malloc_parsed_input = NULL;
        int command_len = 0, directory_len = 0, path_check_result = 0;
        struct stat file_stat;

        if (parsed_input[0] == '/')
        {
                malloc_parsed_input = malloc(sizeof(char) * (_strlen(parsed_input) + 1));
                malloc_parsed_input = _strcpy(malloc_parsed_input, parsed_input);
                return (malloc_parsed_input);
        }
        path = getpath();
        if (path != NULL)
        {
                path_cpy = malloc(sizeof(char) * (_strlen(path) + 1));
                path_cpy = _strcpy(path_cpy, path);
                command_len = _strlen(parsed_input);
                path_token = strtok(path_cpy, delim);
                while (path_token != NULL)
                {
                        directory_len = _strlen(path_token);
                        command_path = malloc(command_len + directory_len + 2);
                        _strcpy(command_path, path_token);
                        _strcat(command_path, "/");
                        _strcat(command_path, parsed_input);

                        path_check_result = stat(command_path, &file_stat);
                        if (path_check_result == 0)
                        {
                                free(path_cpy);
                                return (command_path);
                        }
                        else
                        {
                                free(command_path);
                                path_token = strtok(NULL, delim);
                        }
                }
        }
        return (NULL);
}

/**
 * execute_command - Function executes the command
 *
 * @argv: Argument vector
 * @command: Command parsed by the user to be executed
 *
 * Return: Void
 */
void execute_command(char **argv, char *command)
{
        int execve_result, status;
        pid_t fork_result;

        if (command != NULL)
        {
                fork_result = fork();

                if (fork_result == -1)
                {
                        perror("$ fork() failed");
                }
                else if (fork_result == 0)
                {
                        execve_result = execve(command, argv, NULL);

                        if (execve_result == -1)
                        {
                                free(command);
                                perror("$ execve() failed");
                                exit(EXIT_FAILURE);
                        }
                }
                else
                {
                        waitpid(fork_result, &status, 0);
                }
        }
        else
        {
                perror(command); /* Need to print "[command]: No such file or directory"*/
        }
}

/**
 * exit_shell - Function exits the shell
 */
void exit_shell(void)
{
        write(STDOUT_FILENO, "Leaving Shell.. Bye!\n", 21);
        exit(EXIT_SUCCESS);
}

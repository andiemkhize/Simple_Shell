#ifndef SHELL_H
#define SHELL_H
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#define TOKEN_DELIM " :\n\t"
#define MAX_TOKENS 64

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>

/**
 * struct builtins - Struct for holding the builtins
 * @name: name of builtin command
 * @function: Pointer to a function
 */
typedef struct builtins
{
	char *name;
	void (*function)(char **env);
} builtin;

/* Simple Shell core functions */
void print_prompt(void);
char *read_input(void);
char **parse_input(char *user_input, char **argv, int argc);
char *find_path(char *parsed_input);
void execute_command(char **argv, char *command, char **env);

/* Builtin functions */
void exit_builtin(char **env);
void printenv_builtin(char **env);

#endif

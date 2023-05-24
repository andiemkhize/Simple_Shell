#ifndef SHELL_H
#define SHELL_H
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"

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
char **parse_input(char *str, char **argv, int argc);
char *find_path(char *parsed_input, char **env);
void execute_command(char **argv, char *command);

/* Builtin functions */
void exit_builtin(char **env);
void printenv_builtin(char **env);

/* Helper functions */
char *getpath(char **env);
int _strncmp(const char *s1, const char *s2, int n);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, const char *src);
int _strlen(char *str);
int _strcmp(char *s1, char *s2);

#endif

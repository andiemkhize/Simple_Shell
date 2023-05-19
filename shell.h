#ifndef SHELL_H
#define SHELL_H

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
        void (*function)();
} builtin;

/* Simple Shell core functions */
char *read_input(void);
char **parse_input(char *str, char **argv, int argc);
char *find_path(char *parsed_input);
void execute_command(char **argv, char *command);

/* Builtin functions */
void exit_shell(void);
void print_env(void);

/* Helper functions */
char *getpath(void);
int _strncmp(const char *s1, const char *s2, int n);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, const char *src);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);

#endif

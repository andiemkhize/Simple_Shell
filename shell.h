#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_TOKENS 64
#define TOKEN_DELIM " :\t\n"

char **tokenize_input(char *input);
void free_tokens(char **tokens);
void execute_command(char **tokens, char **env);

#endif

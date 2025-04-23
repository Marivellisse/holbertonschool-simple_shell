#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

extern char **environ;

char **tokenize_input(char *line);
char *find_full_path(char *command);
int handle_builtin(char **args);
void free_args(char **args);

#endif /* SIMPLE_SHELL_H */


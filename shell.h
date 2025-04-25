#ifndef SHELL_H
#define SHELL_H

/* === STANDARD LIBRARIES === */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

/* === GLOBAL VARIABLES === */
extern char **environ;

/* === FUNCTION PROTOTYPES === */

/* Shell core */
void handle_input(void);
void execute_command(char **args, char *path);
char **parse_input(char *buf);

/* Built-ins */
void handle_env(void);

char *find_in_path(char *cmd);
char *_build_full_path(char *dir, char *cmd);
char *get_file_path(char *file_name);
char *get_file_loc(char *path, char *file_name);
char *_getenv(const char *name);
int isAbsolutePath(const char *str);
int check_exit(char *command);

size_t _strcspn(const char *s, const char *accept);
char *trim_whitespace(char *str);
int _isspace(char c);

#endif /* SHELL_H */


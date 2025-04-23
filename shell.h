#ifndef SHELL_H
#define SHELL_H

/* ======= LIBRARIES ======= */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

/* ======= GLOBAL VARIABLES ======= */

extern char **environ;

/* ======= PROTOTYPES ======= */

/* ======= FUNCTIONS 1 ======= */
size_t _strcspn(const char *s, const char *accept);
void handle_input(void);
char **parse_input(char *buf);
void execute_command(char **args, char *path);
void handle_env(void);

/* ======= FUNCTIONS 2 ======= */
int check_exit(char *command);
int isAbsolutePath(const char *str);
char *get_file_loc(char *path, char *file_name);
char *_getenv(const char *name);
char *get_file_path(char *file_name);

#endif

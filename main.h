#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void execute_command(char **args, char *path);
char *find_in_path(char *cmd);

char *_build_full_path(char *dir, char *cmd);


extern char **environ;

#endif


#include "main.h"
#include <stdlib.h>

/**
 * execute_command - Forks and executes a command
 * @argv: Argument vector with command and NULL
 */
void execute_command(char *argv[])
{
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return;
	}
	if (pid == 0)
	{
		if (execve(argv[0], argv, environ) == -1)
		{
			perror(argv[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
	}
}


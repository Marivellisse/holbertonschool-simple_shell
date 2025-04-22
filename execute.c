#include "main.h"
#include <stdlib.h>

/**
 * execute_command - Forks and executes a command
 * @argv: Argument vector with command and NULL
 */
void execute_command(char *argv[])
{
	pid_t pid;
	char *cmd_path;

	cmd_path = find_in_path(argv[0]);
	if (!cmd_path)
	{
		perror(argv[0]);
		return;
	}

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		free(cmd_path);
		return;
	}
	if (pid == 0)
	{
		if (execve(cmd_path, argv, environ) == -1)
		{
			perror(argv[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
	}
	free(cmd_path);
}


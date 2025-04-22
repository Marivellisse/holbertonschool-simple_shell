#include "main.h"

/**
 * main - Entry point of shell
 * Return: Always 0
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	pid_t pid;
	char *argv[2];

	while (1)
	{
		printf("$ "); /* prompt */

		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			printf("End of file or error.\n");
			free(line);
			break;
		}

		if (line[read - 1] == '\n')
			line[read - 1] = '\0';

		argv[0] = line;
		argv[1] = NULL;

		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			continue;
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
	free(line);
	return (0);
}


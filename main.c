#include "main.h"
#include <ctype.h>
#include <string.h>

/**
 * main - Entry point for the simple shell
 *
 * Return: Always 0
 */

/**
 * trim_whitespace - Removes leading and trailing spaces from a string
 * @str: input string
 * Return: pointer to the trimmed string
 */
char *trim_whitespace(char *str)
{
	char *end;

	while (isspace((unsigned char)*str))
		str++;

	if (*str == 0) /* Empty string */
		return (str);

	end = str + strlen(str) - 1;
	while (end > str && isspace((unsigned char)*end))
		end--;

	end[1] = '\0';
	return (str);
}

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	pid_t pid;
	char *argv[2];

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);

		read = getline(&line, &len, stdin);
		if (read == -1)
			break;

		if (line[read - 1] == '\n')
			line[read - 1] = '\0';

		argv[0] = trim_whitespace(line); /* Clean space */
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


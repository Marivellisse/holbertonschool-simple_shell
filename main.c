#include "main.h"
#include "utils.h"

/**
 * main - Entry point for the simple shell
 * Return: Always 0
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
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

		argv[0] = trim_whitespace(line);
		argv[1] = NULL;

		execute_command(argv);
	}

	free(line);
	return (0);
}


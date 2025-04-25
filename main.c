#include "shell.h"
#include "simple_shell.h"

/**
 * main - Entry point for the simple shell
 *
 * Return: Always 0
 */
int main(void)
{
	char *line = NULL, *path = NULL;
	size_t len = 0;
	ssize_t read;
	char **args;
	int interactive = isatty(STDIN_FILENO);

	while (1)
	{
		if (interactive)
			write(STDOUT_FILENO, "$ ", 2);

		read = getline(&line, &len, stdin);
		if (read == -1)
			break;

		if (line[read - 1] == '\n')
			line[read - 1] = '\0';

		args = tokenize_input(line);
		if (!args || !args[0])
		{
			free_args(args);
			continue;
		}

		path = find_full_path(args[0]);

		if (!path)
		{
			write(STDERR_FILENO, "./hsh: 1: ", 10);
			write(STDERR_FILENO, args[0], strlen(args[0]));
			write(STDERR_FILENO, ": not found\n", 12);
			free_args(args);
			continue;
		}

		execute_command(args, path);

		free(path);
		free_args(args);
	}

	free(line);
	return (0);
}


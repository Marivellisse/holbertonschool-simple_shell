#include "main.h"
#include "utils.h"
#include "simple_shell.h"

/**
 * main - Entry point for the simple shell
 * Return: Always 0
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char **args;
	char *path;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);

		read = getline(&line, &len, stdin);
		if (read == -1)
			break;

		if (line[read - 1] == '\n')
			line[read - 1] = '\0';

		/* Tokeniza la línea en argumentos */
		args = tokenize_input(line);
		if (!args || !args[0])
		{
			free_args(args);
			continue;
		}

		/* Obtiene la ruta completa del comando */
		path = find_full_path(args[0]);
		if (path == NULL)
		{
			write(STDERR_FILENO, args[0], strlen(args[0]));
			write(STDERR_FILENO, ": command not found\n", 20);
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


#include "shell.h"

/**
 * _strcspn - Copy of strcspn function of the string library
 * @s: The string to search
 * @accept: The characters to avoid
 *
 * Return: The length of the initial substring.
 */
size_t _strcspn(const char *s, const char *accept)
{
	size_t i = 0;

	while (s[i] != '\0')
	{
		if (strchr(accept, s[i]) != NULL)
			return (i);
		i++;
	}
	return (i);
}

/**
 * parse_input - Tokenizes the input buffer into an array of arguments
 * @buf: Input buffer
 * Return: Array of arguments
 */
char **parse_input(char *buf)
{
	char *token;
	char **array;
	size_t i = 0;

	array = malloc(sizeof(char *) * 1024);
	if (array == NULL)
	{
		perror("Failed to allocate memory");
		free(buf);
		exit(1);
	}

	token = strtok(buf, " \n\t\r");
	while (token)
	{
		array[i] = token;
		token = strtok(NULL, " \n\t\r");
		i++;
	}
	array[i] = NULL;

	return (array);
}

/**
 * execute_command - Executes a command using execve
 * @args: Tokenized command (e.g. {"ls", "-l", NULL})
 * @path: Full path to the executable (e.g. "/bin/ls")
 */
void execute_command(char **args, char *path)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
		return;
	}

	if (pid == 0)
	{
		if (execve(path, args, environ) == -1)
		{
			perror("execve");
			exit(127);
		}
	}
	else
	{
		int status;
		wait(&status);
	}
}

/**
 * handle_input - Handles user input, parses it, and executes the command
 */
void handle_input(void)
{
	char *buf = NULL;
	size_t count = 0;
	ssize_t nread;
	char **args;
	char *path;

	if (isatty(STDIN_FILENO))
		printf("#cisfun$ ");

	nread = getline(&buf, &count, stdin);
	if (nread == -1)
	{
		free(buf);
		exit(0);
	}

	args = parse_input(buf);
	if (!args || !args[0])
	{
		free(args);
		free(buf);
		return;
	}

	if (strcmp(args[0], "exit") == 0)
	{
		free(args);
		free(buf);
		exit(0);
	}

	if (strcmp(args[0], "env") == 0)
	{
		handle_env();
		free(args);
		free(buf);
		return;
	}

	path = get_file_path(args[0]);
	if (!path)
	{
		fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
		free(args);
		free(buf);
		exit(127);
	}

	execute_command(args, path);

	free(path);
	free(args);
	free(buf);
}

/**
 * handle_env - Prints the current environment
 */
void handle_env(void)
{
	char **env = environ;
	unsigned int i = 0;

	while (env[i] != NULL)
	{
		printf("%s\n", env[i]);
		i++;
	}
}


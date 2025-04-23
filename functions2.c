#include "shell.h"

/**
 * check_exit - Checks if the command is "exit" and terminates the program
 *              if it is.
 * @command: The command to check.
 *
 * Return: 1 if command is "exit", 0 if the command is exit.
 */
int check_exit(char *command)
{
	if (strcmp(command, "exit") == 0)
	{
		free(command);
		exit(0);
		return (1);
	}
	return (0);
}


/**
 * isAbsolutePath - Checks if file starts with "/"
 * @str: The filename to be checked
 *
 * Return: 0 if yes and 1 if NO
 */

int isAbsolutePath(const char *str)
{
	if (str != NULL || str[0] == '/')
	{
		return (1);
	}
	return (0);
}

/**
 * get_file_loc - Get the executable path of file
 * @path: Full path variable
 * @file_name: The executable file
 *
 * Return: Full path to the executable file
 */
char *get_file_loc(char *path, char *file_name)
{
	char *path_copy, *token;
	struct stat file_path;
	char *path_buffer = NULL;

	path_copy = strdup(path);
	token = strtok(path_copy, ":");

	while (token)
	{
		if (path_buffer)
		{
			free(path_buffer);
			path_buffer = NULL;
		}
		path_buffer = malloc(strlen(token) + strlen(file_name) + 2);
		if (!path_buffer)
		{
			perror("Error: malloc failed");
			exit(EXIT_FAILURE);
		}
		strcpy(path_buffer, token);
		strcat(path_buffer, "/");
		strcat(path_buffer, file_name);
		strcat(path_buffer, "\0");

		if (stat(path_buffer, &file_path) == 0 && access(path_buffer, X_OK) == 0)
		{
			free(path_copy);
			return (path_buffer);
		}
		token = strtok(NULL, ":");
	}
	free(path_copy);
	if (path_buffer)
		free(path_buffer);
	return (NULL);
}

/**
 * _getenv - Function that works just like getenv
 * @name: The name of the environment.
 *
 * Return: 0
 */

char *_getenv(const char *name)
{
	char **env = environ;

	for (; *env != NULL; ++env)
	{
		if (strncmp(*env, name, strlen(name)) == 0 && (*env)[strlen(name)] == '=')
		{
			return (*env + strlen(name) + 1);
		}
	}

	return (NULL);
}

/**
 * get_file_path - Get's the full path of the file
 * @file_name: The name of the file.
 *
 * Return: The full path argument to the file
 */
char *get_file_path(char *file_name)
{
	char *path = _getenv("PATH");
	char *full_path;

	if (isAbsolutePath(file_name) && access(file_name, X_OK) == 0)
	{
		return (strdup(file_name));
	}

	if (path == NULL)
	{
		perror("Error: PATH not set");
		return (NULL);
	}

	full_path = get_file_loc(path, file_name);

	if (full_path == NULL)
	{
		return (NULL);
	}

	return (full_path);
}

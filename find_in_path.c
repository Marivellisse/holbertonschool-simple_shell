#include "simple_shell.h"

/**
 * _getenv - Custom implementation of getenv (only for PATH)
 * @name: Name of the variable (e.g., "PATH")
 * Return: Pointer to value string, or NULL
 */
char *_getenv(const char *name)
{
	int i;
	size_t len = strlen(name);

	for (i = 0; environ[i]; i++)
	{
		if (strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
			return (environ[i] + len + 1);
	}
	return (NULL);
}

/**
 * find_full_path - Search for a command in PATH
 * @command: command name (e.g. ls)
 *
 * Return: malloc'd full path or NULL
 */
char *find_full_path(char *command)
{
	char *path, *token, *full_path;
	struct stat st;
	char *path_dup;

	if (strchr(command, '/'))
		return (strdup(command));

	path = _getenv("PATH");
	if (!path)
		return (NULL);

	path_dup = strdup(path);
	if (!path_dup)
		return (NULL);

	token = strtok(path_dup, ":");
	while (token)
	{
		full_path = malloc(strlen(token) + strlen(command) + 2);
		if (!full_path)
		{
			free(path_dup);
			return (NULL);
		}
		sprintf(full_path, "%s/%s", token, command);
		if (stat(full_path, &st) == 0)
		{
			free(path_dup);
			return (full_path);
		}
		free(full_path);
		token = strtok(NULL, ":");
	}
	free(path_dup);
	return (NULL);
}


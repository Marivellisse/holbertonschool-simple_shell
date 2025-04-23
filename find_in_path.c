#include "main.h"
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>

/**
 * _build_full_path - Concatenates dir and cmd into a full path
 * @dir: Directory path
 * @cmd: Command name
 * Return: Full path (must be freed), or NULL
 */
char *_build_full_path(char *dir, char *cmd)
{
	int len;
	char *full_path;

	len = strlen(dir) + strlen(cmd) + 2;
	full_path = malloc(len);
	if (!full_path)
		return (NULL);

	snprintf(full_path, len, "%s/%s", dir, cmd);
	return (full_path);
}

/**
 * find_in_path - Finds the full path of a command using PATH env
 * @cmd: Command name (e.g., "ls")
 * Return: Full path if found (malloc'd), else NULL
 */
char *find_in_path(char *cmd)
{
	char *path, *token, *full_path;
	struct stat st;

	if (!cmd || *cmd == '\0')
		return (NULL);

	if (strchr(cmd, '/'))
		return (strdup(cmd));

	path = getenv("PATH");
	if (!path)
		return (NULL);

	path = strdup(path);
	if (!path)
		return (NULL);

	token = strtok(path, ":");

	while (token)
	{
		full_path = _build_full_path(token, cmd);
		if (!full_path)
		{
			free(path);
			return (NULL);
		}

		if (stat(full_path, &st) == 0)
		{
			free(path);
			return (full_path);
		}

		free(full_path);
		token = strtok(path, ":");
	}

	free(path);
	return (NULL);
}
#include "simple_shell.h"

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

	path = getenv("PATH");
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


#include <string.h>
#include "utils.h"

/**
 * _isspace - Checks if a character is a whitespace
 * @c: Character to check
 * Return: 1 if space-like character, 0 otherwise
 */
int _isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' ||
		c == '\v' || c == '\f' || c == '\r');
}

/**
 * trim_whitespace - Removes leading and trailing whitespace
 * @str: Input string
 * Return: Trimmed string
 */
char *trim_whitespace(char *str)
{
	char *end;

	while (_isspace(*str))
		str++;

	if (*str == 0)
		return (str);

	end = str + strlen(str) - 1;
	while (end > str && _isspace(*end))
		end--;

	end[1] = '\0';
	return (str);
}
#include "simple_shell.h"

/**
 * tokenize_input - Tokenizes input line into args
 * @line: input string
 *
 * Return: NULL-terminated array of strings
 */
char **tokenize_input(char *line)
{
	char *token;
	char **args;
	int i = 0;

	args = malloc(64 * sizeof(char *));
	if (!args)
		return (NULL);

	token = strtok(line, " ");
	while (token)
	{
		args[i++] = strdup(token);
		token = strtok(NULL, " ");
	}
	args[i] = NULL;
	return (args);
}

/**
 * free_args - Frees memory for args
 * @args: NULL-terminated array of strings
 */
void free_args(char **args)
{
	int i;

	if (!args)
		return;

	for (i = 0; args[i]; i++)
		free(args[i]);

	free(args);
}


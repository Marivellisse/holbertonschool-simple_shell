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


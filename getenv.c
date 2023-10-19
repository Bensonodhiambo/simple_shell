#include "shell.h"
/**
 *getenvironment - gets environment
 *@line: parameter to be used to get environment
 *Return: 0
 */

char *getenvironment(char *line)
{
	char *det;

	if (access(line, X_OK) == 0)
		return (line);

	det = getenv("PATH");

	if (det)
	{
		det = see(det, line);
		return (det);
	}

	return (NULL);
}

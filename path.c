#include "shell.h"
/**
 *see -  used to get the path
 *@path: path to be found
 *@cmd: argument used to find path
 *Return: 0
 */

char *see(char *path, char *cmd)
{
	char *delim = ":";
	char *acdup;
	char *tok;
	char *fp;

	acdup = strdup(path);
	tok = strtok(acdup, delim);

	while (tok != NULL)
	{
		fp = malloc(strlen(cmd) + strlen(tok) + 2);

		strcpy(fp, tok);
		strcat(fp, "/");
		strcat(fp, cmd);

		if (access(fp, X_OK) == 0)
		{
			free(acdup);
			return (fp);
		}
		tok = strtok(NULL, delim);
		free(fp);
	}
	free(acdup);
	return (NULL);
}

#include "shell.h"
/**
 *getpath -  used to get the path
 *@path: path to be found
 *@cmd: argument used to find path
 *Return: 0
 */

void getpath(char *cmd, char path[])
{
	char *acdup, *tok;

	if (access(cmd, X_OK) == 0)
		return;
	acdup = strdup(getenv("PATH"));
	tok = strtok(acdup, ":");

	while (tok != NULL)
	{
		memset(path, 0, 256);
		strcpy(path, tok);
		strcat(path, "/");
		strcat(path, cmd);

		if (access(path, X_OK) == 0)
		{
			break;
		}
		tok = strtok(NULL, ":");
	}
	free(acdup);
}


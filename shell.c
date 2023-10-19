#include "shell.h"

int main(int argc, char *av[], char **environ);
/**
 *main - main function
 *@argc:count of argumments
 *@av:argument
 *@environ:argument to get environ
 *Return: 0 Always(success)
  */
int main(int argc, char *av[], char **environ)
{
	char *food = NULL;
	size_t num = 0;
	ssize_t get;
	const char *delim = " \n";
	int i;
	pid_t child;
	int status;
	char path[256];
	char *argv[100];


	(void)argc;
	(void)av;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");
		food = NULL;
		get = getline(&food, &num, stdin);
		if (get == -1)
		{
			free(food);
			break;
		}
		i = 0;
		argv[i] = strtok(food, delim);
		while (argv[i] != NULL)
		{
			i++;
			argv[i] = strtok(NULL, delim);

		}
		if (argv[0] == NULL)
			continue;
		strcpy(path, argv[0]);
		getpath(argv[0], path);
		argv[0] = path;
		if (argv[0] == NULL)
		{
			continue;
		}

		child = fork();
		if (child == 0)
		{
			execve(argv[0], argv, environ);
		}
		else if (child < 0)
		{
			perror("error");
		}
		else
		{
			wait(&status);
		}
		free(food);
	}
	
	
	return (0);
}

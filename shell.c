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
	char *tex;
	char *argv[100];


	(void)argc;
	(void)av;

	while (1)
	{
		printf("$ ");
		get = getline(&food, &num, stdin);
		if (get == -1)
		{
			letprint("Exit shell\n");
			return (-1);
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
		tex = getenvironment(argv[0]);
		if (tex == NULL)
		{
			letprint("nothing\n");
			continue;
		}
		argv[0] = tex;

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
	}
	free(food);
	return (0);
}

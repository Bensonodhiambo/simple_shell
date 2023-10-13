#include "main.h"
/*
 *
 */
int main(int argc,char *argv[])
{
	
	char *food = NULL;
	size_t num = 0;
	ssize_t get;
	char *food_copy;
	const char *delim = " ";
	int num_tokens = 0;
	char *token;
	int i;

	(void)argc, (void)argv;

	while(1)
	{
		prompt();
		get = getline(&food, &num, stdin);
		if (get == -1)
		{
			printf("Exit shell\n");
			exit(1);
		}
		food_copy = malloc(sizeof(char*) * get);
		if (food_copy == NULL)
		{
			perror("tsh: memory allocation fail");
			return (-1);
		}
		strcpy(food_copy,food);
		token = strtok(food,delim);
		while (token != NULL)
		{
			num_tokens++;
			token = strtok(NULL,delim);
		}
		num_tokens++;
		argv = malloc(sizeof(char *) *num_tokens);
		token = strtok(food_copy,delim);

		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(token));
			strcpy(argv[i], token);
			token = strtok(NULL,delim);
		
		}
		argv[i] = NULL;

		execmd(argv);

		printf("%s\n", food);
	
	}
	free(food);
	free(food_copy);
	return (0);
}

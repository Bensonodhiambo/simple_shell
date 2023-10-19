#include "shell.h"
/**
 *execmd- executes program
 *
 *@argv:argument to be executed
 *Return: nothing
 */

void execmd(char **argv)
{
	/*char *command = NULL;*/

	/*if (argv)*/
	/*get command */
	/*command = argv[0];*/

	if (execve(argv[0], argv, NULL) == -1)
	{
		perror("error: ");
	}



}

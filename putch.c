#include "shell.h"
/**
 *putchars - write on the starndard output
 *@c:argument to write
 *Return:0
 */
int putchars(char c)
{
	if (write(STDOUT_FILENO, &c, 1) == -1)
		return (-1);

	return (0);
}

/**
 *letprint - used to print the output
 *@format: argument to be printed
 *Return: received
 */
int letprint(char *format)
{
	int i = 0;
	int received = 0;

	for (i = 0; format[i] != '\0'; i++)
	{
		received += putchars(format[i]);
	}

	return (received);
}

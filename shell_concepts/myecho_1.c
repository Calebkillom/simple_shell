#include <stdio.h>
#include <stdlib.h>
/**
 * main - Main Entry point of the program
 * @argc: no of arguments passed to the command line
 * @argv: pointer array that points to each argument passed.
 *
 * Return: Always 0 (Success)
 */

int main(int argc, char *argv[])
{
	int j;

	for (j = 0; j < argc; j++)
		printf("argv[%d]: %s\n", j, argv[j]);

	exit(EXIT_SUCCESS);
}

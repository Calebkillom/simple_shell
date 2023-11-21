#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point
 * @ac: represents the number of command line arguments
 * @av: pointer to an array of strings
 *
 * Return: Always 0 (success)
 */
int main(int ac, char **av)
{
	int n = 1;

	/*checking the program name*/
	printf(" The program name is: %s\n", av[0]);

	while (av[n])
	{
		printf("The current argument is %d and it is %s\n", n, av[n]);
		n++;
	}
	printf("\n");

	return (0);
}

#include <stdio.h>
#include <stdlib.h>

/**
 * main - the entry point of the program
 *
 * Return: Always 0 (success)
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read_line = 0;

	while (read_line != -1)
	{
		printf("$ ");
		read_line = getline(&line, &len, stdin);
		if (read_line != -1)
			printf("%s", line);
	}
	free(line);

	return (0);
}

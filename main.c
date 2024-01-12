#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "main.h"
/**
 * main - Entry point for the program.
 *
 * Description: This function serves as the entry point for the program.
 * It initializes variables, prompts the user for input,
 * tokenizes the input, and executes the corresponding command.
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	const char display_prompt[] = "$ ";
	char *line = NULL;
	size_t len = 0;
	ssize_t read_line = 0;

	while (prompt_and_read(display_prompt, &line, &len, &read_line))
	{
		char **tokens;
		int i;

		/* Tokenize the input line into command and arguments */
		tokens = genToken(line);

		/* Execute the command with arguments */
		process_command(tokens, read_line);

		/* Free memory allocated for tokens */
		free(line);
		line = NULL;

		for (i = 0; tokens[i] != NULL; i++)
		{
			free(tokens[i]);
		}
		free(tokens);
	}

	return (0);
}

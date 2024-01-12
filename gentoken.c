#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
/**
 * genToken - Tokenizes a string into an array of strings.
 * @input: The input string to be tokenized.
 *
 * Return: Array of dynamically allocated strings representing the tokens.
 *			The last element of the array is set to NULL.
 *
 */

char **genToken(char *input)
{
	int i = 0;
	char **cmd_commands, **tmp, *token;

	cmd_commands = malloc(sizeof(char *));

	if (cmd_commands == NULL)
	{
		perror("Memory Allocation failed!");
		exit(EXIT_FAILURE);
	}
	token = strtok(input, " \n");

	while (token != NULL)
	{
		tmp = realloc(cmd_commands, (i + 2) * sizeof(char *));
		if (tmp == NULL)
		{
			perror("Memory allocation for a token failed");
			exit(EXIT_FAILURE);
		}
		cmd_commands = tmp;

		cmd_commands[i] = malloc(strlen(token) + 1);

		if (cmd_commands[i] == NULL)
		{
			perror("Memory allocation for a token failed");
			exit(EXIT_FAILURE);
		}
		strcpy(cmd_commands[i], token);
		printf("%s ", cmd_commands[i]);
		i++;
		token = strtok(NULL, " \n");
	}

	cmd_commands[i] = NULL;
	return (cmd_commands);
}

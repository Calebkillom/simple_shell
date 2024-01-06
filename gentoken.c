#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

char **genToken(int argc, char *argv[])
{
	int i, token_total;

	i = 0;
	token_total = 0;

	/* enforce user to enter something in the command*/
	if (argc < 2)
	{
		perror("Please Enter your Input!");
		exit(EXIT_FAILURE);
	}

	/* Count the Number of Tokens in the input String */
	char *token_count = strtok(argv[1], " ");
	
	while (token_count != NULL)
	{
		token_total++;
		token_count = strtok(NULL, " ");
	}

	/* Dynamically allocate memory for an array of strings */
	char **cmd_commands = (char **)malloc((token_count + 1) * sizeof(char *));

	/* Check if Memory Allocation was successful. */
	if (cmd_commands == NULL)
	{
		perror("Memory Allocation failed!");
		exit(EXIT_FAILURE);
	}

	/* Extract the Input string and split it into Tokens */
	char *token = strtok(argv[1], " ");

	/* copy the current token to the allocated memory */
	while (token != NULL)
	{
		cmd_commands[i] = strdup(token);

		if (cmd_commands[i] == NULL)
		{
			perror("Memory allocation for a token failed");
			exit(EXIT_FAILURE);
		}

		token = strtok(NULL, " ");
		i++;
	}
	cmd_commands = NULL;

	return (cmd_commands);
}

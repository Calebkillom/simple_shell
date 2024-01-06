#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

char **genToken(int argc, char *argv[])
{
	int i = 0;
	int token_total = 0;

	if (argc < 2)
	{
		perror("Please Enter your Input!");
		exit(EXIT_FAILURE);
	}

	char *token_count = strtok(argv[1], " ");

	while (token_count != NULL)
	{
		token_total++;
		token_count = strtok(NULL, " ");
	}

	char **cmd_commands = (char **)malloc((token_total + 1) * sizeof(char *));

	if (cmd_commands == NULL)
	{
		perror("Memory Allocation failed!");
		exit(EXIT_FAILURE);
	}

	char *token = strtok(argv[1], " ");

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

	cmd_commands[token_total] = NULL;
	return (cmd_commands);
}

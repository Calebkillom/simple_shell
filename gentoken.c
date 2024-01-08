#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int countTokens(char *input)
{
	int token_total = 0;
	char *tokenCount = strtok(input, " ");

	while (tokenCount != NULL)
	{
		token_total++;
		tokenCount = strtok(NULL, " ");
	}

	return (token_total);
}

char **genToken(int argc, char *argv[])
{
	int i = 0;
	int tokenTotal = countTokens(argv[1]);
	char **cmd_commands = (char **)malloc((tokenTotal + 1) * sizeof(char *));
	char *token = strtok(argv[1], " ");

	if (argc < 2)
	{
		perror("Please Enter your Input!");
		exit(EXIT_FAILURE);
	}

	if (cmd_commands == NULL)
	{
		perror("Memory Allocation failed!");
		exit(EXIT_FAILURE);
	}

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

	cmd_commands[tokenTotal] = NULL;
	return (cmd_commands);
}

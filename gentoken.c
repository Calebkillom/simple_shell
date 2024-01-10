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

char **genToken(char *input)
{
	int i = 0;
	int tokenTotal = countTokens(input);
	char **cmd_commands, *token;

	printf("Inside genToken\n");
	printf("Input Line: %s\n", input);

	cmd_commands = (char **)malloc((tokenTotal + 1) * sizeof(char *));
	token = strtok(input, " \n");

	if (cmd_commands == NULL)
	{
		perror("Memory Allocation failed!");
		exit(EXIT_FAILURE);
	}

	printf("Tokens: ");

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
	printf("\n");

	cmd_commands[tokenTotal] = NULL;
	return (cmd_commands);
}

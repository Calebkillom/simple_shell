#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

/*int countTokens(char *input)
{
	int token_total = 0;
	char *tokenCount = strtok(input, " \n");

	while (tokenCount != NULL)
	{
		token_total++;
		tokenCount = strtok(NULL, " \n");
	}

	return (token_total);
}*/

char **genToken(char *input)
{
	int i = 0;
	/*int tokenTotal = countTokens(input);*/
	char **cmd_commands, **tmp, *token;

	printf("Inside genToken\n");
	printf("Input Line: %s\n", input);

	cmd_commands = malloc(sizeof(char *));

	if (cmd_commands == NULL)
	{
		perror("Memory Allocation failed!");
		exit(EXIT_FAILURE);
	}
	token = strtok(input, " \n");
	printf("Tokens: ");

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
	printf("\n");

	cmd_commands[i] = NULL;
	return (cmd_commands);
}

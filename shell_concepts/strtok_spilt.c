#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

char **stringSplit(int argc, char *argv[]);

/**
 * main - Entry point to this program
 * Description: This program splits a a string and returns a string array
 *
 * @argc: checks the count of the arguments on command line
 * @argv: represents the command line arguments
 *
 * Return: Always 0 (Success)
 */

int main(int argc, char *argv[])
{
	char **result;

	result = stringSplit(argc, argv);

	/*Printing the whole array of tokens*/
	for (int i = 0; result[i] != NULL; i++)
	{
		printf("%s ", result[i]);
	}
	printf("\n");

	/* Printing the resulting tokens individually */
	printf("\nIndividual tokens:\n");
	for (int i = 0; result[i] != NULL; i++)
	{
		printf("Token %d: %s\n", i, result[i]);
		free(result[i]); /*Free memory allocated for each token*/
	}

	free(result); /*Free memory allocated for the array of tokens*/

	return (0);
}

/**
 * stringSplit - splits and tokenize strings
 *
 * @argc: checks the count of the arguments on command line
 * @argv: represents the command line arguments
 *
 * Return: The array of each word in the string
 */

char **stringSplit(int argc, char *argv[])
{
	int i = 0;

	/* make sure the user enters something in the command line*/
	if (argc < 2)
	{
		perror("please enter your input!");
		exit(EXIT_FAILURE);
	}

	/* Dynamically allocating memory for an array and checking errors*/
	char **cmd_commands = (char **)malloc((strlen(argv[1]) + 1) * sizeof(char *));

	/*extracting the srting*/
	char *token = strtok(argv[1], " ");

	if (cmd_commands == NULL)
	{
		perror("Memory allocation for the array failed");
		exit(EXIT_FAILURE);
	}

	/*splitting the string and inserting it into the cmd_commands array*/
	while (token != NULL)
	{
		cmd_commands[i] = strdup(token);
		if (cmd_commands[i] == NULL)
		{
			perror("Nothing was entered into the array");
			exit(EXIT_FAILURE);
		}
		token = strtok(NULL, " ");
		i++;
	}
	cmd_commands[i] = NULL;
	return (cmd_commands);
}

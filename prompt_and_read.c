#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "main.h"
/**
 * prompt_and_read - Displays a prompt, reads a line from stdin, and stores it.
 * @display_prompt: The prompt to be displayed.
 * @line: Pointer to the variable where the line will be stored.
 * @len: Pointer to the variable storing the size of the allocated buffer.
 * @read_line: Pointer to the variable where no of char read will be stored.
 *
 * Return: 1 if successful, 0 if EOF is encountered, exits on failure
 */

int prompt_and_read(const char *display_prompt, char **line, size_t *len,
		ssize_t *read_line)
{
	ssize_t disp_prompt;

	disp_prompt = write(STDOUT_FILENO, display_prompt,
			strlen(display_prompt) - 1);

	if (disp_prompt == -1)
	{
		perror("An error occured");
		_exit(EXIT_FAILURE);
	}
	*read_line = getline(line, len, stdin);

	if (*read_line == -1)
	{
		if (feof(stdin))
		{
			write(STDOUT_FILENO, "\n", 1);
			return (0);
		}
		else
		{
			perror("An error occurred");
			_exit(EXIT_FAILURE);
		}
	}
	if (*read_line > 0 && (*line)[*read_line - 1] == '\n')
	{
		(*line)[*read_line - 1] = '\0';
	}
	return (1);
}

/**
 * token_count - Counts the number of elements in an array of strings.
 * @tokens: The array of strings.
 *
 * Return: The number of elements in the array.
 */

size_t token_count(char **tokens)
{
	size_t count = 0;

	while (tokens[count] != NULL)
	{
		count++;
	}

	return (count);
}

/**
 * execute_command - Executes a command using fork and execve.
 * @full_path: The full path of the command to be executed.
 * @tokens: The array of tokens representing the command.
 * @read_line: The number of characters read from the input.
 */

void execute_command(char *full_path, char **tokens, ssize_t read_line)
{
	char **command;
	size_t i;
	pid_t pid;

	pid = fork();
	(void)read_line;

	if (pid == -1)
	{
		perror("Fork failed");
		free(full_path);
		_exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		command = (char **)malloc((token_count(tokens) + 1) * sizeof(char *));
		if (command == NULL)
		{
			perror("Memory allocation failed");
			free(full_path);
			_exit(EXIT_FAILURE);
		}
		for (i = 0; tokens[i] != NULL; i++)
			command[i] = tokens[i];
		command[token_count(tokens)] = NULL;
		if (execve(full_path, command, NULL) == -1)
		{
			perror("Command execution failed");
			free(full_path);
			free(command);
			_exit(EXIT_FAILURE);
		}
	}
	else
	{
		int status;

		waitpid(pid, &status, 0);
		free(full_path);
	}
}

/**
 * process_command - Processes by searching for full path and executing it.
 * @tokens: The array of tokens representing the command.
 * @read_line: The number of characters read from the input.
 */

void process_command(char **tokens, ssize_t read_line)
{
	char *full_path;

	if (tokens == NULL || tokens[0] == NULL)
	{
		write(STDERR_FILENO, "Failed to tokenize command\n",
				sizeof("Failed to tokenize command\n") - 1);
		return;
	}

	full_path = search_command(tokens[0]);

	/* check if path was found */
	if (full_path == NULL)
	{
		write(STDERR_FILENO, "Command not found\n",
				sizeof("Command not found\n") - 1);
		return;
	}

	execute_command(full_path, tokens, read_line);
}

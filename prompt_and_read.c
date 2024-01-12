#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "main.h"

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
void process_command(const char *line, ssize_t read_line)
{
    char **tokens = genToken(line);
    char *full_path;
    pid_t pid;

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
        free(tokens);
        return;
    }

    /* fork and execute */
    pid = fork();
    (void)read_line;

    if (pid == -1)
    {
        perror("Fork failed");
        free(tokens);
        free(full_path);
        _exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        /*Allocate memory for command array*/
        char **command = (char **)malloc(2 * sizeof(char *));
        if (command == NULL)
        {
            perror("Memory allocation failed");
            free(tokens);
            free(full_path);
            _exit(EXIT_FAILURE);
        }

        /* Set values for command array*/
        command[0] = full_path;
        command[1] = NULL;

        /* Execute the command*/
        if (execve(full_path, command, NULL) == -1)
        {
            perror("Command execution failed");
            free(tokens);
            free(full_path);
            free(command);
            _exit(EXIT_FAILURE);
        }
    }
    else
    {
        int status;
        waitpid(pid, &status, 0);
        free(tokens);
        free(full_path);
    }
}

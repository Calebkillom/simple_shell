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
	pid_t pid = fork();
	(void)read_line;

	if (pid == -1)
	{
		perror("Fork failed");
		_exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		const char *command[2];

		command[0] = line;
		command[1] = NULL;

		if (execve(line, (char *const *)command, NULL) == -1)
		{
			perror("Command not found");
			_exit(EXIT_FAILURE);
		}
	}
	else
	{
		int status;

		waitpid(pid, &status, 0);
	}
}

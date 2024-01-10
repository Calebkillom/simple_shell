#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "main.h"

char *check_absolute_path(const char *command)
{
	char *path, *result;

	path = strdup(command);
	result = NULL;

	if (access(path, X_OK) == 0)
	{
		result = strdup(path);
	}
	free (path);
	return (result);
}

char *search_command(const char *command)
{
	char *path = getenv("PATH");
	char *path_copy = strdup(path);
	char *dir = strtok(path_copy, ":");

	if (command[0] == '/')
	{
		return (check_absolute_path(command));
	}

	while (dir != NULL)
	{
		char *full_path = (char *)malloc(strlen(dir) + strlen(command) + 2);

		if (full_path == NULL)
		{
			perror("Memory Allocation didn't occur");
			exit(EXIT_FAILURE);
		}

		strcpy(full_path, dir);
		strcat(full_path, "/");
		strcat(full_path, command);

		/*check if the command exists in the directory*/
		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		}
		free(full_path);

		dir = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}

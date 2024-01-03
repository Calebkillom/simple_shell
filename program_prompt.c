#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "main.h"

int main(void)
{
	const char display_prompt[] = "#cisfun$_";
	char *line = NULL;
	size_t len = 0;
	ssize_t read_line = 0;

	while (prompt_and_read(display_prompt, &line, &len, &read_line))
	{
		process_command(line, read_line);
	}
	free(line);
	return (0);
}

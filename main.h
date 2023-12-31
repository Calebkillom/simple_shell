#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>
#include <unistd.h>
#define PROMPT "$ "
int prompt_and_read(const char *display_prompt, char **line, size_t *len,
				ssize_t *read_line);
void process_command(const char *command, ssize_t read_line);
int countTokens(char *input);
char **genToken(int argc, char *argv[]);

#endif

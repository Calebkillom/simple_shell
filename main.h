#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>
#include <unistd.h>
#include <stddef.h>
#define PROMPT "$ "
int prompt_and_read(const char *display_prompt, char **line, size_t *len,
				ssize_t *read_line);
void process_command(char **tokens, ssize_t read_line);
int countTokens(char *input);
char **genToken(const char *input);
char *check_absolute_path(const char *command);
char *search_command(const char *command);

#endif

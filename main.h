#ifndef MAIN_H
#define MAIN_H

int prompt_and_read(const char *display_prompt, char **line, size_t *len,
				ssize_t *read_line);
void process_command(const char *command, ssize_t read_line);

#endif

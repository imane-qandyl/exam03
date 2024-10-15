#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdio.h>

#define BUFFER_SIZE 42
char *get_next_line(int fd);
#endif
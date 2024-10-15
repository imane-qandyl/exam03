#include "get_next_line.h"

char *get_next_line(int fd)
{
    int i = 0;
    char *buffer;
    char c;
    int j;

    if((fd < 0) || (BUFFER_SIZE <= 0))
        return(NULL);
    j = read(fd, &c, 1);
    buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    while(j > 0)
    {
        buffer[i++] = c;
        if(c == '\n')
            break;
        j = read(fd, &c ,1);
    }
    if((j <= 0 ) && (i == 0))
    return (free(buffer), NULL);
    buffer[i] = '\0';
    return(buffer);
}
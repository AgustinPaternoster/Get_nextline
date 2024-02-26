#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>



char *get_next_line(int fd);
int ft_strlen(char *str);
void *ft_strcpy(char *dst, char *str);
char *ft_strdup(char *str);
char *ft_strjoin(char *s1, char *s2);
int ftfindchar(char *str ,int size);

#endif


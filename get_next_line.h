#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

 typedef struct s_list
{
    char    *strbuff;
    struct s_list *next;
    
}t_list;

int checkline(char *line);
t_list *lstnewnode(char *str);
void lstaddnode(t_list **lista, t_list *node);
char	*get_next_line(int fd);
char *cleanline(t_list **lista , int len);
char *get_line(t_list **lista);
int appendlist(t_list **lista, char *buffer);


#endif


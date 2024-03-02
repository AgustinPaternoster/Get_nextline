#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#include <stdio.h>

 typedef struct s_list
{
    void *content;
    struct s_list *next;
    
}t_list;

//t_list	*get_next_line(int fd);
char	*get_next_line(int fd);
t_list *lstnewnode(void * content);
char *ft_strdup(char *str, int size);
void lstaddback(t_list **lista , t_list *nodo);
int lstsize(t_list *lista);
char *ft_findchr(char * str, int size);
int ft_strlen(char *str);
char *ft_strjoin(t_list **lista);

#endif


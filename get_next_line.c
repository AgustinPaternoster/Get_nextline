#include "get_next_line.h"

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while(str[i])
        i++;
    return (i);
}

char *ft_findchr(char *str, int size)
{
    int i;

    i = 0;

    while (i < size)
    {
        if (str[i] == 10)
            return (&str[i]);
        i++;
    }
    return (NULL);
}


char	*get_next_line(int fd)
{
    char buffer[BUFFER_SIZE];
    int chread;
    static int line;
    static char *rest;
    t_list *lista;
    t_list *nodo;
    int countline;

    lista = NULL;
    chread = -1;
    countline = 0;
    while (chread !=0)
    {
        chread = read(fd, buffer,BUFFER_SIZE);
        if (line == countline)
        {
            nodo = lstnewnode(ft_strdup(buffer,chread));
            lstaddback(&lista,nodo);
            if (ft_findchr(buffer,chread))
                break;
        }
        else
            countline++;
    }
    return (ft_strjoin(&lista));
}
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

int Ft_createlst(t_list **list, char *buffer, int chread)
{
    t_list *nodo;

    nodo = lstnewnode(ft_strdup(buffer,chread));
    if (!nodo)
        return (0);
    lstaddback(list,nodo);
    return (1);
}

char	*get_next_line(int fd)
{
    char buffer[BUFFER_SIZE];
    int chread;
    static int line;
    static char *rest;
    t_list *lista;
    int countline;

    lista = NULL;
    chread = -1;
    countline = 0;
    while (chread !=0)
    {
        chread = read(fd, buffer,BUFFER_SIZE);
        if (line == countline)
        {
            if (!Ft_createlst(&lista,buffer,chread))
                return (NULL);    
            if (ft_findchr(buffer,chread))
                break;
        }
        else
            countline++;
    }
    return (ft_strjoin(&lista));
}
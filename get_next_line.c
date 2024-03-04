#include "get_next_line.h"

char *get_line(t_list **lista)
{
    char *line;
    int len;
    int i;
    t_list *tmp;

    len = 0;
    tmp = *lista;
    while (tmp != NULL)
    {
        i = 0;
        while (tmp->strbuff[i])
        {
            i++;
            len++;       
        }
        tmp = tmp->next;
    }
    return (prepline(lista,len));
    //xxxxx
    //xxxxx
    //xxxxx
    //xxxxx
    //xxxxx
    //xxxxx
}

int appendlist(t_list **lista, char *buffer)
{
    t_list *tmp;
    t_list *node;

    node = lstnewnode(buffer);
    if (!node)
    {
        free(buffer);
        return (0);
    }
    lstaddnode(lista,node);
    return (1);
}

char	*get_next_line(int fd)
{
    char *buffer;
    static t_list *lista;
    int chread;
    t_list *node;

    buffer = NULL;
    lista = NULL;
    if (fd < 0 || BUFFER_SIZE == 0 || read(fd, buffer, 0) < 0)
        return (NULL); 
    while(!checkline(buffer))
    {
        buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
        if (!buffer)
            return (NULL);
        chread = read(fd, buffer, BUFFER_SIZE);
        if (chread == 0)
            break;
        buffer[chread] = '\0';
        if(!appendlist(&lista,buffer))
            return (NULL);
    }
    //xxxxx
    //xxxxx
    //xxxxx   
    return (get_line(&lista));
}   
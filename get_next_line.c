#include "get_next_line.h"
void lstclean(t_list **list, char *line)
{
    char *rest;
    size_t *toclean;
    size_t *tmp;
    int i;

    

}

char *get_line(t_list **lista)
{
    char *line;    
    int len;
    int i;
    t_list *tmp;
    char *next_line;

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
    line = malloc(sizeof(char) * len + 1);
    if(!line)
        return(NULL);
    next_line = prepline(lista,line);
    return (next_line);
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
    //free(buffer);  
    return (get_line(&lista));
}   
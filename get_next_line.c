#include "get_next_line.h"

int addtolist(t_list **list, int fd)
{
    t_list *node;
    int chread;
    char *buffer;

    while(!checkline(buffer))
    {
        buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
        if (!buffer)
            return (0);
        chread = read(fd,buffer,BUFFER_SIZE);
        if (chread == 0)
        {
            free(buffer);
            return(1); 
        }
        buffer[chread] = '\0';
        node = lstnewnode(buffer);
        if (!node)
            return(0);
        lstaddnode(list,node);
    }
    //aaaaaa
    //aaaaaa
    return (1);
}


char	*get_next_line(int fd)
{
    
    static t_list *lista = NULL;
    char *nextline;

    if (fd < 0 || BUFFER_SIZE == 0 || read(fd, nextline, 0) < 0)
        return (NULL); 
    if (!addtolist(&lista,fd))
        return (NULL);
    printlst(lista);
    
    return (nextline);
}   
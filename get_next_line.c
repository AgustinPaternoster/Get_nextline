#include "get_next_line.h"
char *lstnextnode(t_list *node)
{
    char *rest;
    int i;
    int len;

    i = 0;
    len = 0;
    while(node->strbuff[i] != '\n')
        i++;
    printf("i:%d\n",i);
    while(node->strbuff[i + len])
        len++;
    printf("i:%d\n",len);
    rest = malloc(sizeof(char) + len);
    if (!rest)
        return(NULL);
    rest[--len] = '\0';
    while (--len >= 0)
    {
        rest[len] = node->strbuff[i + 1 + len];
    }
    return (rest);
}

int dealloclst(t_list **lista)
{
    char *rest;
    t_list *node;
    int len;
    
    if ((node = checkline(*lista)) == NULL)
        {
            lstclean(lista);
            return (1);
        }
    //printf("node:%s",node->strbuff);
    rest = lstnextnode(node);
    //printf("rest:%ld",strlen(rest));
    lstclean(lista);
    node = lstnewnode(rest);
    if (!node)
        return (0);
    lstaddnode(lista,node);

    
    

    
   return(1);
}


char * next_line(t_list **lista)
{
    char * nextline;
    int i;
    int k;
    t_list *tmp;

    if (!*lista)
        return (NULL);
    nextline = malloc(sizeof(char) * nextline_len(*lista));
    if(!nextline)
        return(NULL);
    k = 0;
    tmp = *lista;
    while(tmp != NULL)
    {
        i = 0;
        while(tmp->strbuff[i] && tmp->strbuff[i] != '\n')
            nextline[k++] = tmp->strbuff[i++];
        if (tmp->strbuff[i] == '\n')
            nextline[k++] = '\n';
        tmp = tmp->next;
    }
    nextline[k] = '\0';
    return (nextline);
}


int addtolist(t_list **list, int fd)
{
    t_list *node;
    int chread;
    char *buffer;

    while(!checkline(*list))
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
    nextline = next_line(&lista);
    //printf("lst:%d\n",lstsize(lista));
    if(!dealloclst(&lista))
        return (NULL);
    //printf("lst:%d\n",lstsize(lista));
    return (nextline);
}   
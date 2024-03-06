#include "get_next_line.h"



char *cleanline(t_list **lista ,char *line)
{
    char *cleanline;
    int i;

    i = 0;
    while(line[i] && line[i] != '\n')
        i++; 
      
    cleanline = malloc(sizeof(char) * i + 2);
    if (!cleanline)
            return (NULL);
    cleanline[i+1] = '\0';
    cleanline[i] = '\n';
    while(--i >= 0)
        cleanline[i] = line[i];
    printf("l1:%d\n",lstsize(*lista));
    lstclean(lista);
    printf("L2:%d\n",lstsize(*lista));
    if (!addresttolst(lista,checkline(line)))
        return (NULL);
    printf("L3:%d\n",lstsize(*lista));
    //aaaa
    //aaaa
    //aaaa
    return (cleanline);
}
char *prepline(t_list **lista , char *line)
{
     int i;
     int k;
     t_list *tmp;

    tmp = *lista;
    k = 0;
    while (tmp !=NULL)
    {   
        i = 0;
        //printf("1:%s\n",tmp->strbuff);
        while(tmp->strbuff[i])
        {
            line[k] = tmp->strbuff[i];
            i++;
            k++;
        }
        tmp = tmp->next;
        //printf("2:%s\n",line);
    }
    

    //aaaa
    return (cleanline(lista, line));
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
    printf("len:%d\n",len);
    next_line = prepline(lista,line);
    return (free(line), next_line);
}

int appendlist(t_list **lista, char *buffer)
{
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
    //lista = NULL;
    if (fd < 0 || BUFFER_SIZE == 0 || read(fd, buffer, 0) < 0)
        return (NULL); 
    while(!checkline(buffer))
    {
        buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
        if (!buffer)
            return (NULL);
        chread = read(fd, buffer, BUFFER_SIZE);
        if (chread == 0)
            {
            free(buffer);
            break;
            }
        buffer[chread] = '\0';
        if(!appendlist(&lista,buffer))
            return (NULL);
    }
    //xxxxx
    //xxxxx  
    return (get_line(&lista));
}   
#include "get_next_line.h"

char *checkline(char *line)
{
    int i;

    i = 0;
    if (!line)
        return (NULL);
    while (line[i])
    {
        if (line[i] == '\n')
            return(&line[i]);
        i++;
    }
    return(NULL);  
}

t_list *lstnewnode(char *str)
{
    t_list *node;

    if (!str)
        return (NULL);
    node = malloc(sizeof(t_list));
    if (!node)
        return (NULL);
    node->strbuff = str;
    node->next = NULL;
    return (node);
}

void lstaddnode(t_list **lista, t_list *node)
{
    t_list *tmp;

    tmp = *lista;
    if (tmp == NULL)
        *lista = node;
    else
    {
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = node;
    }
    

}

// int lstsize(t_list *lista)
// {
//     t_list *tmp = lista;
//     int i = 0;

//     while(tmp != NULL)
//     {
//         i++;
//         tmp = tmp->next;
//     }
//     return (i);
// }

char *prepline(t_list **lista , int len)
{
     char *line;
     int i;
     int k;
     t_list *tmp;

    tmp = *lista;
    line = malloc(sizeof(char) * len + 1);
    if(!line)
        return(NULL);
    k = 0;
    while (tmp !=NULL)
    {   
        i = 0;
        while(tmp->strbuff[i])
        {
            line[k] = tmp->strbuff[i];
            i++;
            k++;
        }
        tmp = tmp->next;
    }
    //aaaa
    //aaaa
    //aaaa
    return (cleanline(lista,line));
} 

char *cleanline(t_list **lista , char *line)
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
    //aaaa
    //aaaa
    //aaaa
    //aaaa
    //aaaa
    //aaaa
    //aaaa
    //aaaa
    return (cleanline);
}

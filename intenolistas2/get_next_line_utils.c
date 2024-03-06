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
            return(&line[i + 1]);
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

int lstsize(t_list *lista)
{
    t_list *tmp = lista;
    
    int i = 0;
    while(tmp != NULL)
    {
        i++;
        tmp = tmp->next;
    }
    return (i);
}


void lstclean(t_list **lista)
{
    t_list *tmp;
    t_list *toclean;

    toclean = *lista;
    while (toclean != NULL)
    {
        tmp = toclean->next;
        free(toclean->strbuff);
        free(toclean);
        toclean = tmp;
    }
    *lista = NULL;

    //ddddd
    //ddddd
    //ddddd
    //ddddd
    //ddddd
    //ddddd
    //ddddd
}

int addresttolst(t_list **lista, char *line)
{
    int i;
    t_list *node;
    char *rest;

    i = 0;
    if(!line) // revisar si la linea termina en \n
        return (1);
    while(line[i])
        i++;
    rest = malloc(sizeof(char) * i + 1);
    if (!rest)
        return (0);
    rest[i] = '\0';
    while(--i >= 0)
        rest[i] = line[i];
    node = lstnewnode(rest);
    if(!node)
    {
        free(rest);
        return (0);
    }
    lstaddnode(lista,node);
    return (1);
}
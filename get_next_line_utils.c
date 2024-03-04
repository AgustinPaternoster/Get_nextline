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

// void addnextline(t_list **lista, char *line)
// {
    
//     int i;
//     t_list *node;


// }
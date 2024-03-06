#include "get_next_line.h"

int checkline(char *line)
{
    int i;

    i = 0;
    if (!line)
        return (0);
    while (line[i])
    {
        if (line[i] == '\n')
            return(1);
        i++;
    }
    return(0);  
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

/// @brief ///////////////////////////////////////////////////////////


void printlst(t_list *list)
{
    int i = 1;
    while(list != NULL)
    {
        printf("lst node %d :%s\n",i , list->strbuff);

        list = list->next;
        i++;
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


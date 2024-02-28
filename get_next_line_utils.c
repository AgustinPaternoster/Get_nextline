#include "get_next_line.h"

t_list *lstnewnode(void * content)
{
    t_list *node;
    node = malloc(sizeof(t_list));
    if (!node)
        return (NULL);
    node->content = content;
    node->next = NULL;

    return (node);
}

char *ft_strdup(char *str, int size)
{
    char 	*p;
	int		i;

    if (!str)
        return NULL;

    p = malloc(sizeof(char) * size + 1);
    if (!p)
        return(NULL);
	i = 0;
    while (i < size)
	{
		p[i] = str[i];
		i++;
	}
	p[size] = '\0';
    return (p);
}

void lstaddback(t_list **lista , t_list *nodo)
{
    t_list *tmp;

    tmp = *lista;
    if (!tmp)
        *lista = nodo;
    else
    {
        while(tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = nodo;
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

void ft_strconcat(char *dst ,char *src)
{
    int i;
    int lendst;

    i = 0;
    lendst = ft_strlen(dst);
    while (src[i])
    {
        dst[lendst + i] = src[i];
        i++;
    }
    dst[lendst + i] = '\0';
}


char *ft_strjoin(t_list **lista)
{
    t_list *tmp;
    char *strtmp;
    char *result;
    int size;


    size = 0;
    tmp = *lista;
    if (!tmp)
        return (NULL);
    while(tmp !=NULL)
    {
        size += ft_strlen((char *)tmp->content);
        tmp = tmp->next;
    }
    strtmp = malloc(sizeof(char) * size);
    if(!strtmp)
        return (NULL);
    tmp = *lista;
    while(tmp !=NULL)
    {
        ft_strconcat(strtmp ,(char *)tmp->content);
        tmp = tmp->next;
    }
    return (strtmp);
}

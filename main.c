#include "get_next_line.h"
#include <stdio.h>

 

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

int main(void)
{
    char *lista;
    int fd = open("./test.txt",O_RDONLY);

    lista = get_next_line(fd);
    printf("%s",lista);
    return (0);
}
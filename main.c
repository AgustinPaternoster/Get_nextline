#include "get_next_line_bonus.h"
#include <stdio.h>


int main(void)
{
    char *lista = "XX";
    int i = 1;

    int fd = open("./test2.txt",O_RDONLY);
    lista = get_next_line(fd);
    printf("-line %d:\n%s",i,lista);
    i++;
    lista = get_next_line(fd);
    printf("-line %d:\n%s",i,lista);


    // while (lista != NULL)
    // {
    //     lista = get_next_line(fd);
    //     printf("-line %d:\n%s",i,lista);
    //     free(lista);
    //     i++;
    // }

    return (0);
}
#include "get_next_line.h"
#include <stdio.h>


int main(void)
{
    char *lista = "XX";
    int i = 0;

    int fd = open("./test2.txt",O_RDONLY);
    lista = get_next_line(fd);
    printf("line:%s",lista);

    // while (lista != NULL)
    // {
    //     lista = get_next_line(fd);
    //     printf("line %d:%s",i,lista);
    //     free(lista);
    //     i++;
    // }

    return (0);
}
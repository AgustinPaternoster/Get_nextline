#include "get_next_line.h"
#include <stdio.h>


int main(void)
{
    char *lista = "XX";
    int i = 1;

    int fd = open("./test.txt",O_RDONLY);
    while (lista != NULL)
    {
        lista = get_next_line(fd);
        printf("-line %d:\n%s",i,lista);
        free(lista);
        i++;
    }

    return (0);
}
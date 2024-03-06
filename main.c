#include "get_next_line.h"
#include <stdio.h>


int main(void)
{
    char *lista;
    int fd = open("./test.txt",O_RDONLY);
    lista = get_next_line(fd);
    printf("result:%s",lista);
    lista = get_next_line(fd);
    printf("result:%s",lista);
    lista = get_next_line(fd);
    printf("result:%s",lista);
    lista = get_next_line(fd);
    printf("result:%s",lista);
    lista = get_next_line(fd);
    printf("result:%s",lista);
    return (0);
}
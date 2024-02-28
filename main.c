#include "get_next_line.h"
#include <stdio.h>

int main(void)
{

    

    int fd = open("./test.txt",O_RDONLY);
    char *line = get_next_line(fd);
    printf("LI:%s\n",line);
    line = get_next_line(fd);
    printf("LI:%s\n",line);
    line = get_next_line(fd);
    printf("LI:%s\n",line);
    line = get_next_line(fd);
    printf("LI:%s\n",line);
    return (0);

    

    

}
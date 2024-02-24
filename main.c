#include "get_next_line.h"


int main(void)
{
    int fd;

    fd = open("./test.txt",O_RDONLY);
    get_next_line(fd);
    return 0;
}

#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
	int fd = open("./test.txt",O_RDONLY);
	char *p = get_next_line(fd);
	printf("%s",p);
	return 0;
}

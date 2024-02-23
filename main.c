#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	int bf = 10;
	char buffer[bf];
	int i = 0;
	int fd = open("./test.txt",O_RDONLY);
	int ch = -1;

	while ( ch != 0 )
	{	
		ch = read(fd,buffer,bf);
		int i = 0;
		while (buffer[i] != '\n')
		{	
			write(1,&buffer[i],1);
			i++;
		}
	}
	return (0);
}

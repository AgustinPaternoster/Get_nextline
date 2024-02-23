#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int find_newLine(char *str, int size)
{
	int i;

	while(i < size )
	{
		
	}	
}


void get_next_line(fd)
{
	int bf = 25;
	char buffer[bf];
	int i = 0;
	int fd = open("./test.txt",O_RDONLY);
	int ch = -1;
	int Cline = 0
	static int readline = 0

	while ( ch != 0)
	{	
		ch = read(fd,buffer,bf);
		if (cline 
		int i = 0;
		while (buffer[i] != '\n' & i < bf & ch !=0  )
		{	
			write(1,&buffer[i],1);
			i++;
		}
		if (buffer[i] == '\n')
			cline++
	}
	line++
}


int main(void)
{
	
	int fd = open("./test.txt",O_RDONLY);

	return (0);
}

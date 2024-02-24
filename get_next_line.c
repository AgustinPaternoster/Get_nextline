# include "get_next_line.h"

int ftfindchar(char *str ,int size)
{
	int i;
	
	i = 0;
	while(i < size)
	{
		if(str[i] == 10)
			return (1);
		i++;
	}
	return (0);
}

int putstr(char *str, int size)
{
    int i = 0;

    while (i < size & str[i] != 10)
    {
        write(1,&str[i],1);
        i++;
    }
    return (i);
    
}

char *get_next_line(int fd)
{
    int lt = -1;
    int bf = 10;
    char buffer[bf];
	static readline = 0;
	int cline = 0;

	while (lt != 0)
    {
		lt = read(fd,buffer,bf);
        if (lt == -1)
            return(NULL);
        putstr(buffer,lt);
		if(ftfindchar(buffer,lt))
			break;
    } 
	printf("\nFIN DE LINEA");
	return(NULL); 
}  
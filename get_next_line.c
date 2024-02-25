# include "get_next_line.h"




char *get_next_line(int fd)
{
    int lt = -1;
    int bf = 10;
    char buffer[bf];
	static int readline = 0;
	int cline = 0;

	while (lt != 0)
    {
		lt = read(fd,buffer,bf);
        if (lt == -1)
            return(NULL);
		
		if (readline == cline)
		{
        	putstr(buffer,lt);
			if(ftfindchar(buffer,lt))
			{
				readline++;
				return(NULL); 
			}
		if(ftfindchar(buffer,lt))
			cline++;
		}
    }
	return(NULL); 
}  
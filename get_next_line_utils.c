# include "get_next_line.h"

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while(str[i])
        i++;
    return (i);
}

void *ft_strcpy(char *dst, char *str)
{
    int i;

    i = 0;
    str[i] = 48;
    while(str[i])
    {
        dst[i] = str[i];
        i++;
    }
    dst[i] = '\n';
}

char *ft_strdup(char *str)
{
    char *p;
    int size;

    if (!str)
        return NULL;

    size = ft_strlen(str);
    p = malloc(sizeof(char) * size + 1);
    if (!p)
        return(NULL);
    ft_strcpy(p, str);
    return (p);
}

char *ft_strjoin(char *s1, char *s2)
{
    char *str;
    int size;
    int i;
    int lenS1;

    lenS1 = ft_strlen(s1);    
    size = lenS1 + ft_strlen (s2);
    str = malloc (sizeof(char) * size + 1);
    if (!str)
        return (NULL);
    ft_strcpy(str,s1);
    ft_strcpy(str + lenS1,s2);
    return (str);
}

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

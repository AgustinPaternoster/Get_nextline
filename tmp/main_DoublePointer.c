#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

char  *test(char **p)
{
    char *resul = malloc(sizeof(char)* 3);
    int i = 0;
    while(i < 2)
    {
        resul[i] = p[0][i];
        i++;
    }
    free(*p);
    *p = resul;
}

int main(void)
{
    char *txt = "ABCDES";
	char *p = ft_strdup(txt,6);
    printf("%s\n",p);
    printf("%p\n",p);
    test(&p);
    printf("%s\n",p);
    printf("%p\n",p);
    return 0;
}

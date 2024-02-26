#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
    char str[5] = "XXXX";
    char str2[5] ="QQQQ";
    char *p = ft_strdup(str);
    char *pp = ft_strdup(str2);
    char *ppp = ft_strjoin(p,pp);
    printf("%s",ppp);
    return 0;
}

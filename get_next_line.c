#include "get_next_line.h"

char *appendlist(t_list **lista, int fd)
{
    t_list *tmp;
    t_list node;
    int chread;


    while (checkline(tmp))
    {

    }


}

char	*get_next_line(int fd)
{
    char *strline;
    static t_list *lista;
    int chread;

    lista = NULL;
    strline = NULL;
    if (fd < 0 || BUFFER_SIZE == 0)
        return (NULL); 
    while(checkline(strline))
    {
        strline = malloc(sizeof(char) * BUFFER_SIZE + 1);
        if (!strline)
            return (NULL);
        chread = read(fd, strline, BUFFER_SIZE);
        if (chread == 0)
            break;
                   
    }
    

        
    

}   
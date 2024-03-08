
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>

typedef struct s_list
{
	char			*strbuff;
	struct s_list	*next;

}				t_list;

t_list	*checkline(t_list *lista);
char	*get_next_line(int fd);
int		addtolist(t_list **list, int fd);
int		nextline_len(t_list *lista);
char	*next_line(t_list **lista);
int		dealloclst(t_list **lista);
void	lstclean(t_list **lista);
char	*lstnextnode(t_list *node);
int		lstappend(t_list **lista, char *buff, int fd);
char	*ft_calloc(size_t count, size_t size);

#endif
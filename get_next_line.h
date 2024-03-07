/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:55:49 by apaterno          #+#    #+#             */
/*   Updated: 2024/03/07 12:55:58 by apaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

//////////////
#include <stdio.h>
/////////////
typedef struct s_list
{
	char			*strbuff;
	struct s_list	*next;

}				t_list;

t_list	*checkline(t_list *lista);
t_list	*lstnewnode(char *str);
void	lstaddnode(t_list **lista, t_list *node);
char	*get_next_line(int fd);
int		addtolist(t_list **list, int fd);
int		nextline_len(t_list *lista);
char	*next_line(t_list **lista);
int		dealloclst(t_list **lista);
void	lstclean(t_list **lista);
char	*lstnextnode(t_list *node);
#endif
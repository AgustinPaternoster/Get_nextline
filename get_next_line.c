/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:42:37 by apaterno          #+#    #+#             */
/*   Updated: 2024/03/07 12:42:43 by apaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*lstnextnode(t_list *node)
{
	char	*rest;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (node->strbuff[i] != '\n')
		i++;
	i++;
	while (node->strbuff[i + len])
		len++;
	rest = malloc(sizeof(char) + len);
	if (!rest)
		return (NULL);
	rest[len] = '\0';
	while (--len >= 0)
	{
		rest[len] = node->strbuff[i + len];
	}
	return (rest);
}

int	dealloclst(t_list **lista)
{
	char	*rest;
	t_list	*node;

	node = checkline(*lista);
	if (node == NULL)
	{
		lstclean(lista);
		return (1);
	}
	rest = lstnextnode(node);
	lstclean(lista);
	if (rest[0] == '\0')
	{
		free(rest);
		return (1);
	}
	node = lstnewnode(rest);
	if (!node)
		return (0);
	lstaddnode(lista, node);
	return (1);
}

char	*next_line(t_list **lista)
{
	char	*nextline;
	int		i;
	int		k;
	t_list	*tmp;

	nextline = malloc(sizeof(char) * nextline_len(*lista) + 1);
	if (!nextline)
		return (NULL);
	k = 0;
	tmp = *lista;
	while (tmp != NULL)
	{
		i = 0;
		while (tmp->strbuff[i] && tmp->strbuff[i] != '\n')
			nextline[k++] = tmp->strbuff[i++];
		if (tmp->strbuff[i] == '\n')
			nextline[k++] = '\n';
		tmp = tmp->next;
	}
	nextline[k] = '\0';
	return (nextline);
}

int	addtolist(t_list **list, int fd)
{
	t_list	*node;
	int		chread;
	char	*buffer;

	while (!checkline(*list))
	{
		buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!buffer)
			return (0);
		chread = read(fd, buffer, BUFFER_SIZE);
		if (chread == 0)
		{
			free(buffer);
			return (1);
		}
		buffer[chread] = '\0';
		node = lstnewnode(buffer);
		if (!node)
			return (0);
		lstaddnode(list, node);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static t_list	*lista;
	char			*nextline;

	if (fd < 0 || BUFFER_SIZE == 0 || read(fd, &nextline, 0) < 0)
		return (NULL);
	if (!addtolist(&lista, fd))
		return (NULL);
	if (!lista)
		return (NULL);
	nextline = next_line(&lista);
	if (!dealloclst(&lista))
		return (NULL);
	return (nextline);
}

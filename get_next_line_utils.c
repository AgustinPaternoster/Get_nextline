/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:39:12 by apaterno          #+#    #+#             */
/*   Updated: 2024/03/07 12:39:20 by apaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

t_list	*checkline(t_list *lista)
{
	int		i;
	t_list	*tmp;

	tmp = lista;
	while (tmp != NULL)
	{
		i = 0;
		while (tmp->strbuff[i])
		{
			if (tmp->strbuff[i] == '\n')
				return (tmp);
			i++;
		}
		tmp = tmp->next;
	}
	return (NULL);
}

t_list	*lstnewnode(char *str)
{
	t_list	*node;

	if (!str)
		return (NULL);
	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->strbuff = str;
	node->next = NULL;
	return (node);
}

void	lstaddnode(t_list **lista, t_list *node)
{
	t_list	*tmp;

	tmp = *lista;
	if (tmp == NULL)
		*lista = node;
	else
	{
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = node;
	}
}

int	nextline_len(t_list *lista)
{
	int		i;
	int		len;
	t_list	*tmp;

	len = 0;
	tmp = lista;
	while (tmp != NULL)
	{
		i = 0;
		while (tmp->strbuff[i])
		{
			if (tmp->strbuff[i] == '\n')
			{
				len++;
				return (len);
			}
			i++;
			len++;
		}
		tmp = tmp->next;
	}
	return (len);
}

void	lstclean(t_list **lista)
{
	t_list	*tmp;
	t_list	*toclean;

	toclean = *lista;
	while (toclean != NULL)
	{
		tmp = toclean->next;
		free(toclean->strbuff);
		free(toclean);
		toclean = tmp;
	}
	*lista = NULL;
}

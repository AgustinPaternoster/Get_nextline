/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 09:45:24 by apaterno          #+#    #+#             */
/*   Updated: 2024/02/26 13:42:20 by apaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

char	*get_next_line(int fd)
{
	char	buffer[BUFFER_SIZE];
	int 	chread;
	char	*strtmp;
	char	*buf_read;
	int		cline;
	static int readline;
	static char *rest;

	strtmp =NULL;
	cline = 0;
	do
	{
		chread = read(fd,buffer,BUFFER_SIZE);
		if (cline == readline)
		{
			buf_read = ft_strdup(buffer,chread);
			strtmp = ft_strjoin(strtmp,buf_read);
			if (ft_findn(buffer,chread))
			{	
				readline++;
				return (strtmp);
			}	
		}	
		else
			cline++;
	}
	while (chread != 0);
	return (strtmp);
}


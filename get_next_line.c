/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 09:45:24 by apaterno          #+#    #+#             */
/*   Updated: 2024/02/26 11:29:19 by apaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

char	*get_next_line(int fd)
{
	char	*strline;
	int		bf = 10;
	char	buffer[bf];
	int 	chread;
	char	*strtmp;
	char	*buf_read;

	do
	{
		chread = read(fd,buffer,bf);
		buf_read = ft_strdup(buffer,chread);
		strtmp = ft_strjoin(strtmp,buf_read);
		tmp++;
	
	}
	while (chread != 0);
	return (strtmp);
}


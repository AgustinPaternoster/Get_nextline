/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 09:45:14 by apaterno          #+#    #+#             */
/*   Updated: 2024/02/27 12:53:41 by apaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while(str[i])
        i++;
    return (i);
}

void ft_strcpy(char *dst, char *str)
{
    int i;

    i = 0;
    while(str[i])
    {
        dst[i] = str[i];
        i++;
    }
    dst[i] = '\0';
}

char *ft_strdup(char *str, int size)
{
    char 	*p;
	int		i;

    if (!str)
        return NULL;

    p = malloc(sizeof(char) * size + 1);
    if (!p)
        return(NULL);
	i = 0;
    while (i < size)
	{
		p[i] = str[i];
		i++;
	}
	p[size] = '\0';
    return (p);
}

char *ft_strjoin(char *s1, char *s2)
{
    char *str;
    int size;
    int i;
    int lenS1;

	if (!s1)
		s1 = "";
    lenS1 = ft_strlen(s1);   
    size = lenS1 + ft_strlen (s2);
    str = malloc (sizeof(char) * size + 1);
    if (!str)
        return (NULL);
    ft_strcpy(str,s1);
    i = 0;
    while(s2[i])
    {
        str[lenS1 + i] = s2[i];
        i++;
    }
    str[lenS1 + i] = '\0';
    return (str);
}

int ft_findn(char *str ,int size)
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


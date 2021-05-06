/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftudini <ftudini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 16:59:22 by ftudini           #+#    #+#             */
/*   Updated: 2021/05/06 17:31:25 by ftudini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	if (!s)
		return ;
	while (i < n)
	{
		*(unsigned char *)(s + i) = 0;
		i++;
	}
	return ;
}

int	ft_strlen(const char *str)
{
	int	res;

	res = 0;
	while (*str)
	{
		res++;
		str++;
	}
	return (res);
}

char	*ft_realloc(char **line, int flag)
{
	char	*str;
	int		i;

	i = 0;
	if (!*line)
		return (0);
	if (flag)
		str = malloc(ft_strlen(*line) + BUFFER_SIZE + 1);
	else
		str = malloc(ft_strlen(*line) + 1);
	if (!str)
		return (NULL);
	while ((*line)[i])
	{
		str[i] = (*line)[i];
		i++;
	}
	str[i] = 0;
	free(*line);
	return (str);
}

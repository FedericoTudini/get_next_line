/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftudini <ftudini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 20:05:00 by ftudini           #+#    #+#             */
/*   Updated: 2021/05/06 17:43:54 by ftudini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_allocate(char **line, char *buff)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	*line = ft_realloc(line, 1);
	len = ft_strlen(*line);
	while (buff[j] && buff[j] != '\n')
	{
		(*line)[len + j] = buff[j];
		j++;
	}
	(*line)[len + j] = '\0';
	if (!buff[j])
	{
		buff[0] = 0;
		return (0);
	}
	j++;
	while (buff[j])
		buff[i++] = buff[j++];
	buff[i] = '\0';
	return (1);
}

int	ft_check(char **line)
{
	*line = NULL;
	*line = malloc(BUFFER_SIZE + 1);
	if (!*line)
		return (-1);
	ft_bzero(*line, BUFFER_SIZE);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	buff[BUFFER_SIZE + 1];
	int			i;

	if (fd < 0 || fd > 255 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	if (!ft_check(line))
		return (-1);
	if (ft_allocate(line, buff))
	{
		*line = ft_realloc(line, 0);
		return (1);
	}
	i = read(fd, buff, BUFFER_SIZE);
	while (i > 0)
	{
		buff[i] = '\0';
		if (ft_allocate(line, buff))
		{
			*line = ft_realloc(line, 0);
			return (1);
		}
		i = read(fd, buff, BUFFER_SIZE);
	}
	*line = ft_realloc(line, 0);
	return (i);
}

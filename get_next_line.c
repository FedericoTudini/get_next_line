/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftudini <ftudini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 20:05:00 by ftudini           #+#    #+#             */
/*   Updated: 2021/03/15 12:33:40 by ftudini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		store_line(char *str, char **line, size_t r)
{
	size_t		i;
	char		*tmp;

	if (r == 0)
		*line = ft_strdup(str);
	else if (r > 0)
		*line = ft_substr(str, 0, (ft_strchr(str, '\n') - str));
	tmp = ft_strdup(str + (ft_strlen(*line) + ((r > 0) ? +1 : +0)));
	free(str);
	str = tmp;
	return (r == 0 ? 0 : 1);
}

int		get_next_line(int fd, char **line)
{
	size_t			r;
	char			buffer[BUFF_SIZE + 1];
	static char 	*str;
	char			*tmp;

	str = ft_strdup("");
	if (fd < 0 || !line || BUFF_SIZE <= 0)
		return (-1);
	while ((r = read(fd, &buffer, BUFF_SIZE)) > 0 && !ft_strchr(str, '\n'))
	{
		buffer[r] = '\0';
		tmp = ft_strjoin(str, buffer);
		free(str);
		str = tmp;
	}
	if (r < 0)
		return (-1);
	return (store_line(str, line, r));
}

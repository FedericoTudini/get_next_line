/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftudini <ftudini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 20:05:00 by ftudini           #+#    #+#             */
/*   Updated: 2021/03/23 17:51:32 by ftudini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_store_line(char **str, char **tmp, char **line, ssize_t r)
{
	if (r == 0)
		*line = ft_strdup(*str);
	else if (r > 0)
	{
		*line = ft_substr(*str, 0, (ft_strchr(*str, '\n') - *str));
		r = 1;
	}
	*tmp = ft_strdup(*str + ft_strlen(*line) + r);
	free(*str);
	*str = *tmp;
	return (r);
}

int		get_next_line(int fd, char **line)
{
	ssize_t		r;
	char		bf[BUFFER_SIZE + 1];
	static char	*str;
	char		*tmp;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!str && !(str = (char*)malloc(0)))
		return (-1);
	while (!ft_strchr(str, '\n') && (r = read(fd, bf, BUFFER_SIZE)) > 0)
	{
		bf[r] = '\0';
		tmp = ft_strjoin(str, bf);
		free(str);
		str = tmp;
	}
	if (r < 0)
		return (-1);
	return (ft_store_line(&str, &tmp, line, r));
}

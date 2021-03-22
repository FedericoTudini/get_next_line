/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftudini <ftudini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 20:05:00 by ftudini           #+#    #+#             */
/*   Updated: 2021/03/22 22:10:11 by ftudini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void		*ft_memset(void *b, int c, size_t len)
{
	unsigned	char	*ub;

	ub = (unsigned char *)b;
	while (len > 0)
	{
		*ub = c;
		len--;
		ub++;
	}
	return (b);
}

int		ft_store_line(char **str, char **tmp, char **line, ssize_t r)
{
	if (r == 0)
		*line = ft_strdup(*str);
	else if (r > 0)
		*line = ft_substr(*str, 0, (ft_strchr(*str, '\n') - *str));
	*tmp = ft_strdup(*str + (ft_strlen(*line) + ((r > 0) ? +1 : +0)));
	ft_memset(*str, 0, ft_strlen(*str));
	free(*str);
	*str = NULL;
	*str = *tmp;
	return (r == 0 ? 0 : 1);
}

int		get_next_line(int fd, char **line)
{
	ssize_t		r;
	char		bf[BUFF_SIZE + 1];
	static char	*str;
	char		*tmp;

	if (fd < 0 || !line || BUFF_SIZE <= 0)
		return (-1);
	if (!str)
		if (!(str = (char*)malloc(0)))
			return (-1);
		
	while (!ft_strchr(str, '\n') && (r = read(fd, bf, BUFF_SIZE)) > 0)
	{
		bf[r] = '\0';
		tmp = ft_strjoin(str, bf);
		ft_memset(str, 0, ft_strlen(str));
		free(str);
		str = NULL;
		str = tmp;
	}
	if (r < 0)
		return (-1);
	return (ft_store_line(&str, &tmp, line, r));
}

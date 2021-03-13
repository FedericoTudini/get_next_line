/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftudini <ftudini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 20:05:00 by ftudini           #+#    #+#             */
/*   Updated: 2021/03/13 17:52:52 by ftudini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void		store_line(char *str, char **line, size_t r)
{
	size_t		i;
	char		*tmp;
	
	if (r == 0)
		*line = ft_strdup(str);
	if (r < 0)
		return (-1);
	/*
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	printf("str i : %c \n", str[i]);
	*line = ft_substr(str, 0, i);
	printf("line : ", *line);
	tmp = ft_substr(str, i + 1, ft_strlen(str) - ft_strlen(*line));
	free(str);
	str = tmp; */
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
	store_line(str, line, r);
	return (0);
}

int main(int argc, char **argv)
{
	int input_fd;
	char *line;
	
	input_fd = open(argv[1], O_RDONLY);
    if (input_fd == -1) {
			printf("invalid fd");
            return 2;
    }
	printf("%d \n", get_next_line(input_fd, &line));
	printf("%d \n", get_next_line(input_fd, &line));
	printf("%d \n", get_next_line(input_fd, &line));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftudini <ftudini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 20:05:00 by ftudini           #+#    #+#             */
/*   Updated: 2021/03/20 18:18:44 by ftudini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int			store_line(char *str, char **line, size_t r)
{
	char				*tmp;
	long long int		i;

	i = 0;
	if (**line)
		free(*line);
	while (str[i])
	{
		if (str[i] == '\n')
			break ;
		i++;
	}
	if (r == 0)
	{
		*line = ft_strdup(str);
		free(str);
		return (0);
	}
	*line = ft_substr(str, 0, (ft_strchr(str, '\n') - str));
	tmp = ft_substr(str, i + 1, ft_strlen(str) - i);
	free(str);
	str = ft_strdup(tmp);
	free(tmp);
	printf("%s \n", *line);
	return (1);
}

int					get_next_line(int fd, char **line)
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
		str = tmp;
		free(tmp);
	}
	if (r < 0)
		return (-1);
	return (store_line(str, line, r));
}

int main(int argc, char **argv)
 {
 	int input_fd;
 	char *line;

	if (argc < 0)
		return (0);
 	input_fd = open(argv[1], O_RDONLY);
     if (input_fd == -1) {
 			printf("invalid fd");
             return 2;
     }
 	printf("%d \n", get_next_line(input_fd, &line));
 	printf("%d \n", get_next_line(input_fd, &line));
 	printf("%d \n", get_next_line(input_fd, &line));
 }
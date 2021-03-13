/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftudini <ftudini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 18:58:00 by ftudini           #+#    #+#             */
/*   Updated: 2021/03/08 18:05:58 by ftudini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#define BUFF_SIZE 4

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

int		ft_strlen(const char *str)
{
	int res;

	res = 0;
	while (*str)
	{
		res++;
		str++;
	}
	return (res);
}


char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*toreturn;
	int		i;
	int		j;

	if (!s1 || !s2
		|| !(toreturn = malloc(ft_strlen(s1) + 1 + ft_strlen(s2))))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i++])
		toreturn[i - 1] = s1[i - 1];
	while (s2[j++])
		toreturn[i + j - 2] = s2[j - 1];
	toreturn[i + j - 2] = 0;
	return (toreturn);
}

char	*ft_strdup(const char *src)
{
	char	*dst;
	int		i;

	i = 0;
	if (!(dst = (char*)malloc(ft_strlen(src) + 1)))
		return (NULL);
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}


char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*sub;
	size_t		i;

	i = 0;
	if (len > (size_t)ft_strlen(s + start))
		len = (size_t)ft_strlen(s + start);
	if (start >= (unsigned int)ft_strlen(s))
		len = 0;
	if (!(sub = (char*)malloc((len + 1) * sizeof(char))))
		return (NULL);
	while ((i < len) && *(s + start + i))
	{
		sub[i] = *(s + start + i);
		i++;
	}
	sub[len] = 0;
	return (sub);
}

char	*ft_strchr(const char *s, int c)
{
	size_t i;

	i = 0;
	while (s[i])
	{
		if ((char)c == *(char*)(s + i))
		{
			return ((char*)(s + i));
		}
		i++;
	}
	if ((char)c == s[i])
		return ((char*)(s + i));
	return (NULL);
}

#endif
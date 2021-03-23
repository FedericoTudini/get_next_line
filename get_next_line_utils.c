/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftudini <ftudini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 16:59:22 by ftudini           #+#    #+#             */
/*   Updated: 2021/03/23 16:59:00 by ftudini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	char			*str;
	int				i;
	int				j;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	if (!(str = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = 0;
	return (str);
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
	unsigned char	u;

	u = (unsigned char)c;
	while (*s || u == 0)
	{
		if (*s == u)
		{
			return (char*)s;
		}
		s++;
	}
	return (0);
}

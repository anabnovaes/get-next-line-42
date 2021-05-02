/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 19:50:49 by apaula-b          #+#    #+#             */
/*   Updated: 2021/05/02 13:25:44 by apaula-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *dest, char const *org, size_t positions)
{
	char			*join;
	size_t			counter_s1;
	size_t			counter_s2;

	counter_s1 = 0;
	join = (char *)malloc(ft_strlen((char *)dest) + positions);
	if (dest == NULL || org == NULL)
		return (NULL);
	if (!join)
		return (NULL);
	while (dest[counter_s1])
	{
		join[counter_s1] = dest[counter_s1];
		counter_s1++;
	}
	counter_s2 = 0;
	while (counter_s2 < positions && org[counter_s2])
	{
		join[counter_s1 + counter_s2] = org[counter_s2];
		counter_s2++;
	}
	join[counter_s1 + counter_s2] = '\0';
	return (join);
}

size_t	ft_strlen(char *s)
{
	size_t			size;

	size = 0;
	while (s[size])
		size++;
	return (size);
}

size_t	*ft_strchr(char *s, int c)
{
	int	counter;

	counter = 0;
	while (s[counter] != '\0')
	{
		if (s[counter] == c)
			return (counter);
		counter++;
	}
	if (s[counter] == c)
		return (counter);
	return (-1);
}

char	*ft_strdup(const char *s1)
{
	size_t	size_s1;
	char	*s2;

	size_s1 = ft_strlen((char *)s1);
	s2 = malloc(size_s1 + 1);
	if (s1 == NULL)
		return (NULL);
	else if (!s2)
		return (NULL);
	else
	{
		ft_strlcpy(s2, s1, size_s1 + 1);
		return (s2);
	}
}

size_t	ft_strlcpy(char *dst, const char *src, size_t len)
{
	size_t	counter;

	counter = 0;
	if (len == 0)
	{
		return (ft_strlen((char *)src));
	}
	if (dst == NULL && src == NULL)
	{
		return (0);
	}
	while (counter < len - 1 && src[counter])
	{
		dst[counter] = src[counter];
		counter++;
	}
	dst[counter] = '\0';
	return (ft_strlen((char *)src));
}

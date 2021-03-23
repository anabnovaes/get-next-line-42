/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 19:50:49 by apaula-b          #+#    #+#             */
/*   Updated: 2021/03/22 21:49:11 by apaula-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2, size_t positions)
{
	char			*join;
	size_t			counter_s1;
	size_t			counter_s2;

	counter_s1 = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(join = (char *)malloc(ft_strlen(s1) + positions)))
		return (NULL);
	while (s1[counter_s1])
	{
		join[counter_s1] = s1[counter_s1];
		counter_s1++;
	}
	counter_s2 = 0;
	while (counter_s2 < positions && s2[counter_s2])
	{
		join[counter_s1 + counter_s2] = s2[counter_s2];
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

char	*ft_strchr(const char *s, int c)
{
	size_t		counter;

	counter = 0;
	while (s[counter] != '\0')
	{
		if (s[counter] == c)
			return (counter);
		counter++;
	}
	if (s[counter] == c)
		return (counter);
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	size_t		size_s1;
	char		*s2;

	size_s1 = ft_strlen((char *)s1);
	if (s1 == NULL)
		return (NULL);
	else if (!(s2 = malloc(size_s1 + 1)))
		return (NULL);
	else
	{
		ft_strlcpy(s2, s1, size_s1 + 1);
		return (s2);
	}
}

size_t	ft_strlcpy(char *dst, const char *src, size_t len)
{
	size_t		counter;

	counter = 0;
	if (len == 0)
	{
		return (ft_strlen((char *)src));
	}
	if (dst == NULL || src == NULL)
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

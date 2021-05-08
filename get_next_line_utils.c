/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 19:50:49 by apaula-b          #+#    #+#             */
/*   Updated: 2021/05/08 15:04:24 by apaula-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>

char	*ft_strjoin(char *dest, char *org, size_t positions)
{
	char	*temp;

	if (!dest && !org)
		return (NULL);
	temp = malloc((ft_strlen(dest) + positions) * sizeof(char));
	if (!(temp))
		return (NULL);
	ft_strlcpy(temp, dest, (ft_strlen(dest) + 1));
	ft_strlcpy((temp + ft_strlen(dest)), org, positions + 1);
	if (dest)
		free(dest);
	return (temp);
}

size_t	ft_strlen(char *s)
{
	size_t			size;

	size = 0;
	if (!s)
		return (0);
	while (s[size])
		size++;
	return (size);
}

int	ft_strchr(char *s, int c)
{
	int	counter;

	counter = 0;
	if (!s)
		return (-1);
	while (s[counter] != '\0')
	{
		printf("posicao %d\n", s[counter]);
		if (s[counter] == c)
			return (counter);
		counter++;
	}
	if (s[counter] == c)
		return (counter);
	return (-1);
}

void	ft_bzero(char *final_value, size_t n)
{
	size_t	counter;

	counter = 0;
	while (counter < n)
	{
		final_value[counter] = '\0';
		counter++;
	}
}

size_t	ft_strlcpy(char *dst, const char *src, size_t len)
{
	size_t	counter;

	counter = 0;
	if (len == 0)
		return (ft_strlen((char *)src));
	if (src == NULL)
		return (0);
	while (counter < len - 1 && src[counter])
	{
		dst[counter] = src[counter];
		counter++;
	}
	dst[counter] = '\0';
	return (ft_strlen((char *)src));
}

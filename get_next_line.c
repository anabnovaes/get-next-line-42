/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 19:50:53 by apaula-b          #+#    #+#             */
/*   Updated: 2021/05/04 22:02:50 by apaula-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>

static int	read_file(int fd, char *buff, char	*n_line, char **line)
{
	size_t	reading;
	int		posit;
	char	*temp;

	temp = NULL;
	while (ft_strchr(buff, '\n') == -1 && ft_strchr(n_line, '\n') == -1)
	{
		reading = read(fd, buff, BUFFER_SIZE);
		if (reading == 0)
			return (0);
		if ((ft_strchr(buff, '\n') != -1))
		{
			break ;
		}
		else
		{
			posit = BUFFER_SIZE + 1;
			temp = ft_strjoin(temp, buff, posit);
		}
	}
	posit = ft_strchr(buff, '\n');
	temp = ft_strjoin(temp, buff, posit);
	n_line =ft_strjoin(n_line, buff + posit + 1, BUFFER_SIZE - posit);
	printf("estatica :  %s\n", n_line);
	*line = temp;
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*next_line;
	char		*buff;

	if (BUFFER_SIZE <= 0 || fd < 0 )
	{
		return (-1);
	}
	buff = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buff)
	{
		return (-1);
	}
	if (!read_file(fd, buff, next_line, line))
	{
		free(buff);
		return (0);
	}
	return (1);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*pointer;
	size_t	counter;
	char	*final_value;

	pointer = malloc(count * size);
	if (!pointer)
		return (NULL);
	else
	{
		final_value = (char *)pointer;
		while (counter < count)
		{
			final_value[counter] = '\0';
			counter++;
		}
		return (pointer);
	}
}

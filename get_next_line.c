/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 19:50:53 by apaula-b          #+#    #+#             */
/*   Updated: 2021/05/02 13:29:30 by apaula-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	read_file(int fd, char *buff, char *next_line)
{
	size_t	reading;
	size_t	end;
	size_t	positions;

	end = 0;
	positions = BUFFER_SIZE;
	while (end == 0)
	{
		reading = read(fd, buff, BUFFER_SIZE);
		if (reading == 0)
			return (0);
		if ((ft_strchr(buff, "\n") != -1))
		{
			positions = ft_strchr(buff, "\n");
			end = 1;
		}
		ft_strjoin(next_line, buff, positions);
	}
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*next_line;
	char		*buff;

	buff = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (BUFFER_SIZE <= 0 || fd < 0 || !buff)
	{
		free(buff);
		return (-1);
	}
	if (!read_file(fd, buff, &next_line))
	{
		free(buff);
		return (0);
	}

	return (1);
}

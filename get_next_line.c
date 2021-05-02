/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 19:50:53 by apaula-b          #+#    #+#             */
/*   Updated: 2021/05/02 12:56:57 by apaula-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	join_and_concatenate(char *next_line, char *buff)
{
	size_t	counter;
	char	*temp;

	counter = 0;
	while (buff + counter != (char *)"\n" || buff + counter != (char *)"\0")
		counter++;
	temp = ft_strjoin(next_line, buff, counter + 1);
	next_line = ft_strdup(temp);
	free(temp);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*next_line;
	char		*buff;
	size_t		read_file;
	int			end_line;

	end_line = 0;
	buff = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (BUFFER_SIZE < 0 || fd < 0 || !buff)
	{
		free(buff);
		return (-1);
	}
	while (end_line == 0)
	{
		read_file = read(fd, buff, BUFFER_SIZE);
		if (read_file == 0)
		{
			free(buff);
			return (0);
		}
		if (ft_strchr(buff, '\n'))
			end_line = 1;
		join_and_concatenate(next_line, buff);
	}
	 *line = ft_strdup(next_line);
	return (1);
}

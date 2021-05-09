/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 19:50:53 by apaula-b          #+#    #+#             */
/*   Updated: 2021/05/09 00:05:28 by apaula-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"

static int	new_line(char **next_line, char **temp)
{
	int		end_line;
	char	*new_temp;

	end_line = ft_strchr(*temp, '\n');
	temp[0][end_line] = '\0';
	*next_line = ft_strdup(*temp);
	if (!next_line)
		return (0);
	end_line++;
	if (temp[0][end_line])
	{
		new_temp = ft_strdup(*temp + end_line);
		free(*temp);
		*temp = new_temp;
	}
	return (1);
}

int	read_file(int fd, char *buff, char **temp, int *b_read)
{
	while (*b_read && ft_strchr(*temp, '\n') == -1)
	{
		*b_read = read(fd, buff, BUFFER_SIZE);
		if (*b_read < 0 || BUFFER_SIZE < *b_read)
			return (-1);
		if (*b_read)
			*temp = ft_strjoin(*temp, buff, BUFFER_SIZE + 1);
	}
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*temp;
	char		*buff;
	int			b_read;
	int			readed;

	b_read = 1;
	if (fd < 0 || fd > RLIMIT_NOFILE || !(line) || BUFFER_SIZE <= 0)
		return (-1);
	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (-1);
	readed = read_file(fd, buff, &temp, &b_read);
	free(buff);
	if (readed == -1)
		return (-1);
	 new_line(line, &temp);
	if (!line)
		return (-1);
	if (!b_read)
		return (0);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 19:50:53 by apaula-b          #+#    #+#             */
/*   Updated: 2021/05/15 21:55:27 by apaula-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*pointer;
	size_t	counter;
	char	*final_value;

	counter = 0;
	pointer = malloc(count * size);
	if (!pointer)
		return (NULL);
	else
	{
		final_value = (char *)pointer;
		while (counter < size)
		{
			final_value[counter] = '\0';
			counter++;
		}
	}
	return (pointer);
}

static char	*new_line(char **next_line, char **temp)
{
	int		end_line;
	char	*new_temp;

	new_temp = NULL;
	end_line = ft_strchr(*temp, '\n');
	if (end_line != -1)
	{
		temp[0][end_line] = '\0';
		*next_line = ft_strdup(*temp);
		end_line++;
		new_temp = ft_strdup(*temp + end_line);
	}
	else
		*next_line = ft_strdup(*temp);
	free(*temp);
	temp = NULL;
	if (!next_line || !new_temp)
		return (NULL);
	return (new_temp);
}

int	read_file(int fd, char *buff, char **temp, int *b_read)
{
	char	*temp_buff;

	while (*b_read && (ft_strchr(*temp, '\n') == -1))
	{
		*b_read = read(fd, buff, BUFFER_SIZE);
		if (*b_read < 0 || BUFFER_SIZE < *b_read)
		{
			free(buff);
			return (-1);
		}
		if (*b_read)
		{
			temp_buff = NULL;
			if (BUFFER_SIZE > *b_read)
				temp_buff = ft_strjoin(*temp, buff, *b_read);
			else
				temp_buff = ft_strjoin(*temp, buff, BUFFER_SIZE + 1);
			*temp = temp_buff;
		}
	}
	free(buff);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*temp[OPEN_MAX];
	char		*buff;
	int			b_read;
	int			readed;

	b_read = 1;
	if (fd < 0 || fd > RLIMIT_NOFILE || !(line) || BUFFER_SIZE <= 0)
		return (-1);
	buff = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!buff)
		return (-1);
	if (!temp[fd])
		temp[fd] = ft_strdup("");
	readed = read_file(fd, buff, &temp[fd], &b_read);
	if (readed == -1 || !line)
		return (-1);
	if (temp[fd])
		temp[fd] = new_line(line, &temp[fd]);
	if (!b_read)
	{
		free(temp);
		return (0);
	}
	return (1);
}

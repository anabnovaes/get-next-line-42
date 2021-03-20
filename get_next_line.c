/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 19:50:53 by apaula-b          #+#    #+#             */
/*   Updated: 2021/03/20 20:45:19 by apaula-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUFFER_SIZE 60
#include "get_next_line.h"

int		save_and_join(char end_line, char *storage, char *temp, int size_read)
{
	if(end_line == 0)
	{

	}
}

int		read_file_and_save(int fd, char *temp, char file)
{
	int			read_file;
	char		*next_line;
	int			end_line;

	read_file = 0;
	while (read_file <= 0)
	{
		read_file = read(fd, next_line, BUFFER_SIZE);
		end_line = ft_strchr(next_line, "\n");
		if (read_file == BUFFER_SIZE && !end_line)
		{
			temp = ft_strjoin(temp, next_line, BUFFER_SIZE + 1);
			read_file = 0;
		}
		else
			read_file = save_and_join(read_file, next_line, temp, end_line);
	}
	return (read_file);
}

int		get_next_line(int fd, char **line)
{
	static char *file;
	char		*next_line;
	int			read;

	if (BUFFER_SIZE < 0 || fd < 0)
		return (-1);
	if (!(file = (char)malloc(BUFFER_SIZE + 1) * sizeof(char)))
		return (-1);
	read = read_file_and_save(fd, &next_line, file);
	if (read == 0)
		return (0);
	else if (read > 0)
	{
		line[0] = next_line;
		return (1);
	}
	else
		return (-1);
}

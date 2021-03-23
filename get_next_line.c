/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 19:50:53 by apaula-b          #+#    #+#             */
/*   Updated: 2021/03/22 21:23:30 by apaula-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUFFER_SIZE 60
#include "get_next_line.h"

int		read_file(int fd, char *n_line, char file)
{
	size_t		read_file;
	t_line		s_char;
	int			end_line;

	read_file = -2;
	if (!(s_char.read = (char)malloc(BUFFER_SIZE + 1) * sizeof(char)))
		return (-1);
	while (read_file == -2)
	{
		read_file = read(fd, s_char.read, BUFFER_SIZE);
		end_line = ft_strchr(s_char.read, "\n");
		if (read_file == 0)
			return (0);
		else if (read_file < 0)
			return (-1);
		else if (!end_line)
			read_file = -2;
		else
			return (0);
		s_char.line = ft_strjoin(n_line, s_char.line, ft_strlen(s_char.line));
		free(n_line);
		n_line = s_char.line;
	}
	free(s_char.read);
	return (1);
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
	read = read_file(fd, &next_line, file);
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

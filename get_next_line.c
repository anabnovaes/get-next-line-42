/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 19:50:53 by apaula-b          #+#    #+#             */
/*   Updated: 2021/05/05 21:21:50 by apaula-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>

static void	join_and_concat(char *n_line, char **line, char *temp)
{
	int	posit;

	if (!temp)
	{
		temp = n_line;
		free(line);
	}

	posit = ft_strchr(temp, '\n');
	n_line = ft_strjoin(n_line, temp + posit + 1, BUFFER_SIZE - posit);
	*line = ft_strjoin(*line, temp, posit);
	printf("Posit %d \n", posit);
	printf("next line %s \n", n_line);
	printf("line %s \n", n_line);
}

static int	read_file(int fd, char *buff, char	*n_line, char **line)
{
	size_t	reading;
	char	*temp;
	int		check_buff;
	int		check_nline;

	temp = "";
	if (!n_line)
		n_line = NULL;
	check_buff = ft_strchr(buff, '\n') == -1;
	check_nline = ft_strchr(n_line, '\n') != -1;
	printf("buff %d \n", check_buff);
	printf("nline %d \n", check_nline);
	while (ft_strchr(buff, '\n') == -1 && ft_strchr(n_line, '\n') != -1)
	{
		write(1, "entrei \n", 20);
		reading = read(fd, buff, BUFFER_SIZE);
		if (reading == 0)
			return (0);
		if ((ft_strchr(buff, '\n') != -1))
		{
			temp = ft_strjoin(temp, buff, BUFFER_SIZE + 1);
			write(1, "entrei \n", 20);
			printf("temp %s", temp);
			break ;
		}
		else
			temp = ft_strjoin(temp, buff, BUFFER_SIZE + 1);
	}
	join_and_concat(n_line, line, temp);
	free(buff);
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

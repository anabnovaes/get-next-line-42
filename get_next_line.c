/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 19:50:53 by apaula-b          #+#    #+#             */
/*   Updated: 2021/05/08 17:46:39 by apaula-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"

static void	join(char *temp, char *next, char *buff, char **line)
{
	int		pos;

	pos = 0;
	if (ft_strchr(next, '\n') != -1)
	{
		pos = ft_strchr(next, '\n');
		printf("pos %d \n", pos);
		if (next[pos + 1])
		{
			printf("vou unir aqui \n");
			temp = ft_strjoin(temp, next, pos);
			printf("estatica :  %s\n", temp);
		}
		printf("oii \n");
		next =ft_strjoin(next, buff + pos + 1, BUFFER_SIZE - pos);
	}	
	else
	{
		printf("buff concat : %s", buff);
		pos = ft_strchr(buff, '\n');
		printf("pos %d \n", pos);
		if (buff[pos + 1])
		{
			printf("vou concatenar \n");
			next =ft_strjoin(next, buff + pos + 1, BUFFER_SIZE - pos);
			printf("estatica :  %s\n", next);
		}
		printf("vou unir o que falta \n");
	}
	printf("temp :  %s\n", temp);
	*line = temp;
}

int	read_file(int fd, char *buff, char	*n_line, char **line)
{
	int		reader;
	int		posit;
	char	*temp;
	int		is_nothing;

	temp = NULL;
	is_nothing = 0;
	write(1, "antes de verificar n_line\n", 27);
	if (n_line)
	{
		printf("tem coisa na static");
		if (ft_strchr(n_line, '\n') != -1)
		{
			join(temp, n_line, buff, line);
			return (1);
		}
	}
	while (ft_strchr(buff, '\n') == -1 || ft_strchr(buff, '\0') == -1)
	{
		printf("entrei no while \n");
		ft_bzero(buff, sizeof(buff));
		reader = read(fd, buff, BUFFER_SIZE);
		printf("reader : %ld \n", reader);
		printf("read :%s \n", buff);
		if (read == 0)
		{
			is_nothing = 1;
			break ;
		}	
		if ((ft_strchr(buff, '\n') != -1) && !is_nothing)
		{
			printf("entrei no if \n");
			posit = ft_strchr(buff, '\n');
			temp = ft_strjoin(temp, buff, posit);
			join(temp, n_line, buff, line);
			return (1);
		}
		else
		{
			posit = BUFFER_SIZE + 1;
			printf("temp :%s\n", temp);
			temp = ft_strjoin(temp, buff, posit);
			printf("apos join :%s\n", temp);
		}
	}
	if (is_nothing == 1)
		return (0);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*next_line;
	char		*buff;

	printf("inicio execucao \n");
	if (BUFFER_SIZE <= 0 || fd < 0 )
	{
		return (-1);
	}
	buff = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buff)
	{
		return (-1);
	}
	if (read_file(fd, buff, next_line, line) == 0)
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

	counter = 0;
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

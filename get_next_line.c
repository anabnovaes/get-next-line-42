/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 19:50:53 by apaula-b          #+#    #+#             */
/*   Updated: 2021/05/08 15:28:58 by apaula-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"

static void	join_and_concat(char *temp, char *n_line, char *buff, char **line)
{
	int		posit;

	if (ft_strchr(n_line, '\n'))
	{
		posit = ft_strchr(n_line, '\n');
		printf("posit %d \n" , posit);
		if (n_line[posit + 1])
		{
			printf("vou unir aqui \n");
			temp = ft_strjoin(temp, n_line, posit);
			printf("estatica :  %s\n", temp);
		}
		printf("oii \n");
		n_line =ft_strjoin(n_line, buff + posit + 1, BUFFER_SIZE - posit);
	}	
	else
	{
		posit = ft_strchr(buff, '\n');
		printf("posit %d \n", posit);
		if (buff[posit + 1])
		{
			printf("vou concatenar \n");
			n_line =ft_strjoin(n_line, buff + posit + 1, BUFFER_SIZE - posit);
			printf("estatica :  %s\n", n_line);
		}
		printf("vou unir o que falta \n");
		temp = ft_strjoin(temp, buff, posit);
	}
	printf("temp :  %s\n", temp);
	*line = temp;
}

int	read_file(int fd, char *buff, char	*n_line, char **line)
{
	size_t	reading;
	int		posit;
	char	*temp;

	temp = NULL;
	write(1, "antes de verificar n_line\n", 27);
	if (n_line)
	{
		printf("tem coisa na static");
		if (ft_strchr(n_line, '\n') != -1)
		{
			join_and_concat(temp, n_line, buff, line);
			return (1);
		}
	}
	while (ft_strchr(buff, '\n') == -1 || ft_strchr(buff, '\0') == -1)
	{
		printf("entrei \n");
		ft_bzero(buff, sizeof(buff));
		reading = read(fd, buff, BUFFER_SIZE);
		printf("reading :%s \n", buff);
		if (reading == 0)
			return (0);
		if ((ft_strchr(buff, '\n') != -1))
		{
			printf("entrei no if \n");
			join_and_concat(temp, n_line, buff, line);
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

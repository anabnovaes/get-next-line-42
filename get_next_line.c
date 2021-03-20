/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 19:50:53 by apaula-b          #+#    #+#             */
/*   Updated: 2021/03/20 18:21:28 by apaula-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define BUFFER_SIZE 60
#include "get_next_line.h"

int read_file(int fd,char *buffer, char file)
{
	int		read_file;
	size_t	size_to_save;

	read_file = 1;
	while(read_file != 0)
	{
		read_file = read(fd,buffer,BUFFER_SIZE);
		if (ft_strchr(buffer,'\n'))
			
	}
}

int	get_next_line(int fd, char **line)
{
	static char *file[BUFFER_SIZE + 1];
	char		*buffer;
	int		read;

	read = 1;
	if (BUFFER_SIZE < 0 || fd < 0)
		return - 1;
	if (!(buffer = (char)malloc(BUFFER_SIZE) * sizeof(char)))
		return - 1;
	read = read_file(fd, buffer,file);
	if (read == 0)
		return 0;
	
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 19:50:53 by apaula-b          #+#    #+#             */
/*   Updated: 2021/03/17 21:16:06 by apaula-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define BUFFER_SIZE 20
#include "get_next_line.h"
#include<sys/types.h>
#include<sys/stat.h>
#include <fcntl.h> 

int	get_next_line(int fd, char **line)
{
	char *file;
	static char *line[BUFFER_SIZE + 1];
	
	file = read(fd, line, BUFFER_SIZE);
	if (BUFFER_SIZE < 0)
		return - 1;
}

int main(void)
{
}
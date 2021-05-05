/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_tester.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:41:13 by mchardin          #+#    #+#             */
/*   Updated: 2021/05/04 21:46:55 by apaula-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int				get_next_line(int fd, char **line);

int main()
{
	int             fd;
	int             i;
	int             j;
	char    		*line = 0;
	char			*lineadress[66];
	
	j = 1;
	printf("\n==========================================\n");
	printf("========== TEST 1 : The Alphabet =========\n");
	printf("==========================================\n\n");

	if (!(fd = open("files/43_char", O_RDONLY)))
	{
		printf("\nError in open\n");
		return (0);
	}
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("|%s\n", line);
		free(line);
		lineadress[j - 1] = line;
		j++;
	}
	printf("|%s\n", line);
	free(line);
	close(fd);

	if (i == -1)
		printf ("\nError in Function - Returned -1\n");
	else if (j == 66)
		printf("\nRight number of lines\n");
	else if (j != 66)
		printf("\nNot Good - Wrong Number Of Lines\n");
	while (--j > 0)
		free(lineadress[j - 1]);
	j = 1;
}

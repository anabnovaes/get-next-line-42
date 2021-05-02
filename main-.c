/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main-.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 19:58:31 by apaula-b          #+#    #+#             */
/*   Updated: 2021/05/02 11:27:15 by apaula-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdint.h>

int	main(void)
{
	char	*line;
	int		counter;
	int		fd;
	int		gnl;

	line = (char *)malloc(10000);
	counter = 0;
	fd = open("teste.txt", O_RDONLY);
	gnl = 1;
	while (gnl <= 0 && counter <= 60)
	{
		counter++;
		printf("try: \e[1;31m%i\e[0m\n", counter);
		gnl = get_next_line(fd, &line);
	}
	printf("Line: %s ", line);
	printf("\e[32mConcluded!\e[0m\n");
	return (0);
}

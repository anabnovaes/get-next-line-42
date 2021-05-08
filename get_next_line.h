/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 19:51:00 by apaula-b          #+#    #+#             */
/*   Updated: 2021/05/08 15:04:52 by apaula-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <sys/param.h>
# include <sys/resource.h>
# include <fcntl.h>

int		get_next_line(int fd, char **line);

char	*ft_strjoin(char *dest, char *org, size_t positions);

size_t	ft_strlen(char *s);

int		ft_strchr(char *s, int c);

void	ft_bzero(char *final_value, size_t n);

int		read_file(int fd, char *buff, char	*n_line, char **line);

size_t	ft_strlcpy(char *dst, const char *src, size_t len);

void	*ft_calloc(size_t count, size_t size);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 19:51:00 by apaula-b          #+#    #+#             */
/*   Updated: 2021/05/15 21:51:59 by apaula-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <sys/types.h>
# include <sys/stat.h>
# include <sys/resource.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <ctype.h>
# include <limits.h>

int		get_next_line(int fd, char **line);

char	*ft_strjoin(char *dest, char *org, size_t positions);

size_t	ft_strlen(char *s);

int		ft_strchr(char *s, int c);

int		read_file(int fd, char *buff, char **temp, int *b_read);

size_t	ft_strlcpy(char *dst, const char *src, size_t len);

char	*ft_strdup(const char *s1);

#endif

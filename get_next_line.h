/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 19:51:00 by apaula-b          #+#    #+#             */
/*   Updated: 2021/03/22 21:17:17 by apaula-b         ###   ########.fr       */
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

int				get_next_line(int fd, char **line);

char			*ft_strjoin(char const *s1, char const *s2, size_t positions);

size_t			ft_strlen(char *s);

char			*ft_strchr(const char *s, int c);

char			*ft_strdup(const char *s1);

size_t			ft_strlcpy(char *dst, const char *src, size_t len);

typedef struct	s_line
{
	char		line;
	char		read;
	char		apply_to_static;
}				t_line;

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 16:58:32 by jberredj          #+#    #+#             */
/*   Updated: 2020/12/21 14:07:45 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# ifndef FD_MAX
#  define FD_MAX 65536
# endif
# include <unistd.h>
# include <stdlib.h>
# define COPY 1
# define NOCOPY 0
# ifdef MALLOC_FAIL
#  define malloc(x) NULL
# endif
char	*ft_gnljoin(char *s1, char *s2);
size_t	ft_strlcpy(char *dest, char *src, size_t n);
int		get_next_line(int fd, char **line);
void	ft_bzero(void *s, size_t n);
#endif

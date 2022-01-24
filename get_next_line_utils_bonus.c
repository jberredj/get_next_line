/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 17:13:44 by jberredj          #+#    #+#             */
/*   Updated: 2022/01/24 10:30:02 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

static size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	src_len;
	size_t	dest_len;

	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	if (size <= dest_len)
		return (src_len + size);
	dest = &dest[dest_len];
	i = 0;
	while (i < (size - (dest_len) - 1) && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest_len + src_len);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*uchar_s;

	uchar_s = (unsigned char*)s;
	while (n-- > 0)
		*uchar_s++ = '\0';
}

size_t	ft_strlcpy(char *dest, char *src, size_t n)
{
	size_t	i;
	int		str_len;

	str_len = 0;
	while (src[str_len] != '\0')
	{
		str_len++;
	}
	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (str_len);
}

int	ft_gnljoin(char **s1, char *s2)
{
	char	*str;
	size_t	str_len;

	if (*s1 == NULL)
	{
		*s1 = (char *)malloc(sizeof(char));
		if (*s1 == NULL)
			return (-1);
		ft_bzero(s1, 1);
	}
	str_len = ft_strlen(*s1) + ft_strlen(s2) + 1;
	str = (char *)malloc(sizeof(char) * str_len);
	if (str == NULL)
		return (-1);
	ft_strlcpy(str, *s1, str_len);
	ft_strlcat(str, s2, str_len);
	if (*s1 != NULL)
		free(*s1);
	*s1 = str;
	return (0);
}

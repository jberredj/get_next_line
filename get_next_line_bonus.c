/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 16:40:41 by jberredj          #+#    #+#             */
/*   Updated: 2020/12/21 14:14:14 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_endline(char *buffer, char *chest, int param)
{
	int	end;
	int i;
	int j;

	end = 0;
	i = 0;
	j = 0;
	while (buffer[i])
	{
		if (param == COPY && end != 0)
		{
			chest[j] = buffer[i];
			j++;
		}
		if (buffer[i] == '\n')
		{
			end = 1;
			buffer[i] = '\0';
		}
		i++;
	}
	return (end);
}

int	gnl_clean(int code, char **line, char **chest, int fd)
{
	if (code <= 0)
		if (chest[fd] != NULL)
		{
			free(chest[fd]);
			chest[fd] = NULL;
		}
	if (code == -1)
		if (*line != NULL)
		{
			free(line);
			line = NULL;
		}
	return (code);
}

int	check_chest(int fd, char **chest, char **line)
{
	int	line_read;
	int i;

	line_read = 0;
	if (chest[fd] == NULL)
	{
		if (!(chest[fd] = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
			return (gnl_clean(-1, line, chest, fd));
	}
	else
	{
		i = 0;
		line_read = check_endline(chest[fd], chest[fd], NOCOPY);
		while (chest[fd][i++] != '\0')
			;
		if (!(*line = ft_gnljoin(*line, chest[fd])))
			return (gnl_clean(-1, line, chest, fd));
		ft_strlcpy(chest[fd], &chest[fd][i], BUFFER_SIZE);
	}
	if (line_read == 0)
		ft_bzero(chest[fd], sizeof(char) * (BUFFER_SIZE + 1));
	return (line_read);
}

int	get_line(int fd, char **chest, char **line)
{
	char	buffer[BUFFER_SIZE + 1];
	int		end;
	int		read_size;

	end = 0;
	read_size = 0;
	while (end == 0)
	{
		ft_bzero(buffer, sizeof(char) * (BUFFER_SIZE + 1));
		if ((read_size = read(fd, buffer, BUFFER_SIZE)) <= 0)
			return (gnl_clean(read_size, line, chest, fd));
		end = check_endline(buffer, chest[fd], COPY);
		if (!(*line = ft_gnljoin(*line, buffer)))
			return (gnl_clean(-1, line, chest, fd));
	}
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*chest[FD_MAX];
	int			valid_fd;
	int			code;
	int			line_read;

	line_read = 0;
	if ((fd < 0 || fd > FD_MAX) || *line != NULL)
		return (-1);
	if ((valid_fd = read(fd, line, 0)) == -1)
		return (gnl_clean(-1, line, chest, fd));
	if (!(*line = (char*)malloc(sizeof(char))))
		return (gnl_clean(-1, line, chest, fd));
	ft_bzero(*line, sizeof(char));
	if ((line_read = check_chest(fd, chest, line)) != 0)
		return (gnl_clean(line_read, line, chest, fd));
	code = get_line(fd, chest, line);
	return (code);
}

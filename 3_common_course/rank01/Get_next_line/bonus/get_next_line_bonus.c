/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:58:41 by abraekev          #+#    #+#             */
/*   Updated: 2024/04/03 14:09:10 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*free_strs(char **s1, char **s2)
{
	if (s1 &&*s1)
	{
		free(*s1);
		*s1 = NULL;
	}
	if (s2 && *s2)
	{
		free(*s2);
		*s2 = NULL;
	}
	return (NULL);
}

static int	init_malloc(int size, char **str_address)
{
	char	*str;
	int	i;

	str = (*str_address);
	i = -1;
	if (!str)
	{
		str = malloc(size);
		if (!str)
			return (0);
		while (++i < size)
			str[i] = 0;
		*str_address = str;
	}
	return (1);
}

static int	update_line(char *buffer, int bytes_read, char **line)
{
	char	*tmp;
	size_t	line_len;
	size_t	tmp_len;
	size_t	i;

	if (!init_malloc(bytes_read + 1, line))
		return (0);
	line_len = ft_strlen(*line);
	tmp_len = line_len + bytes_read;
	tmp = malloc(tmp_len + 1);
	if (!tmp)
		return (0);
	ft_strlcpy(tmp, *line, tmp_len + 1);
	i = line_len;
	while (i < tmp_len)
	{
		tmp[i] = buffer[i - line_len];
		if (buffer[i - line_len] == '\n' || !buffer[i - line_len])
			break ;
		i++;
	}	
	free(*line);
	*line = tmp;
	return (1);
}

static int	read_and_update(int fd, char **buffer, char **line, int bytes_read)
{
	if (!init_malloc(BUFFER_SIZE + 1, buffer))
		return (-1);
	bytes_read = read(fd, *buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		if (!update_line(*buffer, bytes_read, line))
			return (-1);
		if (ft_strchr(*buffer, '\n'))
		{
			ft_strlcpy(*buffer, ft_strchr(*buffer, '\n') + 1, BUFFER_SIZE + 1);
			break ;
		}
		bytes_read = read(fd, *buffer, BUFFER_SIZE);
	}
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	static char	*buffers[FOPEN_MAX];
	char		*line;
	int		bytes_read;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = NULL;
	if (buffers[fd] && *buffers[fd])
	{
		bytes_read = (int)ft_strlen(buffers[fd]);
		if (!update_line(buffers[fd], bytes_read, &line))
			return (free_strs(&buffers[fd], &line));
		if (ft_strchr(buffers[fd], '\n'))
			ft_strlcpy(buffers[fd], ft_strchr(buffers[fd], '\n') + 1, BUFFER_SIZE + 1);
		else
			buffers[fd][0] = 0;
	}
	if ((!buffers[fd] || !*buffers[fd]) && (!line || !ft_strchr(line, '\n')))
	{
		bytes_read = read_and_update(fd, &buffers[fd], &line, -1);
		if (bytes_read < 0)
			return (free_strs(&buffers[fd], &line));
		if (!bytes_read && buffers[fd])
		{
			// zou hier moeten gaan na laatste buffer
			printf("freeing buffer\n");
			free_strs(&buffers[fd], NULL);
		}
	}
	return (line);
}

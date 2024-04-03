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

static int	init_malloc(int size, char **str_address)
{
	char	*str;

	str = (*str_address);
	if (!str)
	{
		str = malloc(size);
		if (!str)
			return (0);
		str[0] = 0;
		*str_address = str;
	}
	return (1);
}

static int	update_line(char *buffer, int bytes_read, char **line)
{
	char	*tmp;
	size_t	line_len;
	size_t	tmp_len;

	if (!init_malloc(bytes_read + 1, line))
		return (0);
	line_len = ft_strlen(*line);
	tmp_len = line_len + bytes_read;
	tmp = malloc(tmp_len + 1);
	if (!tmp)
		return (0);
	ft_strlcpy(tmp, *line, tmp_len + 1);
	ft_strlcat(tmp, buffer, tmp_len + 1);
	free (*line);
	*line = tmp;
	return (1);
}

static int	last_update(char *buffer, int bytes_read, char **line)
{
	int	i;
	size_t	line_len;
	size_t	tmp_len;
	char	*tmp;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (!init_malloc(bytes_read + 1, line))
		return (0);
	line_len = ft_strlen(*line);
	tmp_len = line_len + i + 1;
	tmp = malloc(tmp_len + 1);
	if (!tmp)
		return (0);
	ft_strlcpy(tmp, *line, tmp_len + 1);
	ft_strlcat(tmp, buffer, tmp_len + 1);
	ft_strlcpy(buffer, buffer + i + 1, bytes_read);
	free (*line);
	*line = tmp;
	return (1);
}



char	*get_next_line(int fd)
{
	static char	*buffers[FOPEN_MAX];
	char		*line;
	int		bytes_read;

		printf("main");
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (buffers[fd] && *buffers[fd])
	{
		last_update(buffers[fd], ft_strlen(buffers[fd]) + 1, &line);
	}
	if ((!buffers[fd] || !*buffers[fd]) && (!line || !ft_strchr(line, '\n')))
	{
		if (!init_malloc(BUFFER_SIZE, &buffers[fd]))
			return (NULL);
		bytes_read = read(fd, buffers[fd], BUFFER_SIZE);
		while (bytes_read > 0)
		{
			if (!update_line(buffers[fd], bytes_read, &line))
				return (NULL);
			if (ft_strchr(buffers[fd], '\n'))
			{
				last_update(buffers[fd], bytes_read, &line);
				break ;
			}
			bytes_read = read(fd, buffers[fd], BUFFER_SIZE);
		}
		if (bytes_read < 0)
			return (NULL);
		if (!bytes_read)
			free(buffers[fd]);
	}
	return (line);
}

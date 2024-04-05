/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:58:41 by abraekev          #+#    #+#             */
/*   Updated: 2024/04/03 14:09:10 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	init_malloc(int size, char **str_address)
{
	char	*str;
	int		i;

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
		i++;
		if (tmp[i - 1] == '\n' || !tmp[i - 1])
			break ;
	}
	tmp[i] = 0;
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
		(*buffer)[bytes_read] = 0;
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

static int	check_and_update(char **buffer, char **line)
{
	int	bytes_read;

	bytes_read = (int)ft_strlen(*buffer);
	if (!update_line(*buffer, bytes_read, line))
		return (0);
	if (ft_strchr(*buffer, '\n'))
		ft_strlcpy(*buffer, ft_strchr(*buffer, '\n') + 1, BUFFER_SIZE + 1);
	else
	{
		free(*buffer);
		*buffer = NULL;
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = NULL;
	if (buffer && *buffer)
		if (!check_and_update(&buffer, &line))
			return (NULL);
	if ((!buffer || !*buffer) && (!line || !ft_strchr(line, '\n')))
	{
		bytes_read = read_and_update(fd, &buffer, &line, -1);
		if (bytes_read < 0)
			return (NULL);
		if (!bytes_read && buffer)
		{
			free(buffer);
			buffer = NULL;
		}
	}
	return (line);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:58:41 by abraekev          #+#    #+#             */
/*   Updated: 2024/03/16 17:22:21 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	init_str(char **str_address)
{
	char	*str;

	str = (*str_address);
	if (!str)
	{
		str = malloc(1);
		if (!str)
			return (0);
		str[0] = 0;
		*str_address = str;
	}
	return (1);
}

static int	update_str(char	*buffer, int bytes_read, char **str_address)
{
	char	*tmp;
	char	*str;

	str = (*str_address);
	tmp = malloc(ft_strlen(str) + bytes_read + 1);
	if (!tmp)
	{
		free(*str_address);
		return (0);
	}
	ft_strlcpy(tmp, str, ft_strlen(str) + 1);
	ft_strlcat(tmp, buffer, ft_strlen(str) + bytes_read + 1);
	free(*str_address);
	*str_address = tmp;
	return (1);
}

static char	*get_buffer(char *str, int fd)
{
	char	buffer[BUFFER_SIZE];
	int		bytes_read;

	if (!init_str(&str))
		return (NULL);
	while (!ft_strchr(str, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		if (!update_str(buffer, bytes_read, &str))
			return (NULL);
	}
	if (bytes_read < 0)
	{
		free(str);
		return (NULL);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	size_t		len;
	char		*nl;

	if (str && *str)
	{
		if (ft_strchr(str, '\n'))
			ft_strlcpy(str, ft_strchr(str, '\n') + 1, ft_strlen(str) + 1);
		else
			str[0] = 0;
	}
	if (!str || !*str || !ft_strchr(str, '\n'))
		str = get_buffer(str, fd);
	if (str && *str)
	{
		nl = ft_strchr(str, '\n');
		if (nl)
			len = nl - str + 1;
		else
			len = ft_strlen(str);
		return (ft_substr(str, 0, len));
	}
	if (str)
		free(str);
	return (NULL);
}

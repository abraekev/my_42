/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:58:41 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/26 17:22:21 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	get_index_nl(t_data *d)
{
	int	i;

	i = 0;
	while (i < (*d).bytes_read)
	{
		if ((*d).buffer[i] == '\n')
		{
			if ((*d).buffer[i + 1] == 0 && i + 1 != BUFFER_SIZE)
				(*d).eof = 1;
			(*d).index = i + 1;
			(*d).substr = (*d).buffer + i + 1;
			return (1);
		}
		i++;
	}
	(*d).index = 0;
	(*d).substr = 0;
	return (0);
}

static char	*gnl_prewhile(t_data *d)
{
	char	*out;
	size_t	len;

	if ((*d).index)
	{
		ft_strlcpy((*d).buffer, (*d).substr, ft_strlen((*d).substr) + 1);
		get_index_nl(d);
		if ((*d).index)
			len = (size_t)(*d).index;
		else
			len = ft_strlen((*d).buffer);
		out = ft_substr((*d).buffer, 0, len);
		if (!out)
			return (NULL);
		return (out);
	}
	(*d).substr = 0;
	return (NULL);
}

static char	*gnl_postwhile_retro(t_data *d, char *out, size_t len)
{
	char	*tmp;
	size_t	t_len;

	tmp = out;
	t_len = ft_strlen(tmp);
	out = malloc(t_len + len);
	if (!out)
	{
		free(tmp);
		return (NULL);
	}
	ft_strlcpy(out, tmp, t_len + 1);
	ft_strlcat(out, (*d).buffer, t_len + len + 1);
	free(tmp);
	return (out);
}

static char	*gnl_postwhile(t_data *d, char *out)
{
	size_t	len;

	if ((*d).index)
		len = (size_t)(*d).index;
	else
		len = ft_strlen((*d).buffer);
	if (out)
		return (gnl_postwhile_retro(d, out, len));
	out = ft_substr((*d).buffer, 0, len);
	if (!out)
		return (NULL);
	return (out);
}

char	*get_next_line(int fd)
{
	static t_data	d = {0};
	char			*out;

	if (fd < 0 || fd == 1 || fd == 2 || BUFFER_SIZE < 1 || d.eof)
		return (NULL);
	out = gnl_prewhile(&d);
	if (out && out[ft_strlen(out) - 1] == '\n')
		return (out);
	d.bytes_read = read(fd, d.buffer, BUFFER_SIZE);
	(d.buffer)[d.bytes_read] = 0;
	while (d.bytes_read > 0)
	{
		if (get_index_nl(&d))
			break ;
		out = gnl_postwhile(&d, out);
		if (!out)
			return (NULL);
		d.bytes_read = read(fd, d.buffer, BUFFER_SIZE);
		(d.buffer)[d.bytes_read] = 0;
	}
	if (d.bytes_read < 0)
		return (NULL);
	if (d.bytes_read == 0)
		d.eof = 1;
	return (gnl_postwhile(&d, out));
}

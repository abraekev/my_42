/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 09:43:42 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/28 13:20:00 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	read_error(char *filepath)
{
	if (errno != 0)
	{
		ft_error("ft_tail: error reading \'");
		ft_error(filepath);
		ft_error("\': ");
		ft_errno(-1);
		ft_error("\n");
	}
}

int	ft_tail(char *filepath, int bytes_asked)
{
	int		fd;
	char	buf[BUF_SIZE];
	int		bytes_read;

	fd = open(filepath, O_RDONLY);
	if (fd != -1)
	{
		bytes_read = read(fd, buf, BUF_SIZE);
		while (bytes_read > 0)
		{
			if (bytes_read < bytes_asked)
				bytes_asked = bytes_read;
			write(1, &buf[bytes_read - bytes_asked], bytes_asked);
			bytes_read = read(fd, buf, BUF_SIZE);
		}
		if (bytes_read == -1)
			read_error(filepath);
		close (fd);
		return (1);
	}
	else
		return (0);
}

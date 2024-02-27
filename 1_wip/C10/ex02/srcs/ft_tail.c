/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 09:43:42 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/27 16:00:03 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

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
			write(1, &buf[bytes_read - bytes_asked], bytes_asked);
			bytes_read = read(fd, buf, BUF_SIZE);
		}
		return (1);
	}
	else
		return (0);
}

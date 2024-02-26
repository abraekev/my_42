/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 13:06:55 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/26 12:42:16 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display_file.h"
#include <fcntl.h>
#include <unistd.h>

void	display_file(char *filepath)
{
	char		buf[4096 + 1];
	int			fd;
	int			buf_size;
	int			ret;

	fd = open(filepath, O_RDONLY);
	if (fd == -1)
	{
		error_msg("Cannot read file.");
		return ;
	}
	buf_size = 4096;
	ret = read(fd, buf, buf_size);
	while (ret)
	{
		buf[ret] = '\0';
		ft_putstr(buf);
		ret = read(fd, buf, buf_size);
	}
	close(fd);
}

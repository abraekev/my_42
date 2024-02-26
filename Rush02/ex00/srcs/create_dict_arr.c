/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_dict_arr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 13:06:55 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/25 21:50:01 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

// geef 4096 mee als buf_size

char	**create_dict_array_assign(int ret, char *buf, int buf_size, int fd)
{
	char	**dict_array;

	while (ret)
	{
		buf[ret] = '\0';
		dict_array = ft_split(buf, "\n");
		ret = read(fd, buf, buf_size);
	}
	if (!(dict_array))
		return (NULL);
	return (dict_array);
}

char	**create_dict_arr(char *filepath, int buf_size)
{
	char		*buf;
	char		**dict_array;
	int			fd;
	int			ret;

	fd = open(filepath, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Cannot read file.\n");
		return (NULL);
	}
	buf = malloc(buf_size + 1);
	if (!buf)
		return (0);
	ret = read(fd, buf, buf_size);
	dict_array = create_dict_array_assign(ret, buf, buf_size, fd);
	close(fd);
	free(buf);
	if (!dict_array)
		return (NULL);
	return (dict_array);
}

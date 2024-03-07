/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:26:59 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/27 13:04:29 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	read_error(char *filepath)
{
	if (errno != 0)
	{
		ft_error("ft_cat: ");
		ft_error(filepath);
		ft_error(": ");
		ft_errno(-1);
		ft_error("\n");
	}
}

int	ft_cat(char *filepath)
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
			ft_ult_putstr(buf, 1, bytes_read);
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

void	no_arg(char **argv)
{
	char	buf;

	while (read(0, &buf, 1) != 0)
	{
		if (errno == 0)
			ft_putchar(buf);
		else
		{
			ft_error(basename(argv[0]));
			ft_error(": stdin: ");
			ft_errno(-1);
			ft_error("\n");
		}
	}
}

void	cat_error(char **argv, int i)
{
	if (errno != 0)
	{
		ft_error(basename(argv[0]));
		ft_error(": ");
		ft_error(argv[i]);
		ft_error(": ");
		ft_errno(-1);
		ft_error("\n");
	}
}

int	main(int argc, char **argv)
{
	int		i;

	if (argc == 1)
	{
		no_arg(argv);
		return (0);
	}
	i = 0;
	while (++i < argc)
	{
		if (ft_cat(argv[i]) == 0)
			cat_error(argv, i);
	}
	return (0);
}

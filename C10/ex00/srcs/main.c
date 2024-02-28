/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 09:32:28 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/28 10:26:34 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display_file.h"

void	ft_putchar(char c, int out)
{
	write(out, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str, int out, int len)
{
	int	i;

	if (!len)
		len = ft_strlen(str);
	i = -1;
	while (++i < len)
		ft_putchar(str[i], out);
}

void	display_file(char *filepath)
{
	char		buf[4096 + 1];
	int			fd;
	int			size;	

	fd = open(filepath, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Cannot read file.\n", 2, 0);
		return ;
	}
	size = read(fd, buf, 4096);
	while (size)
	{
		buf[size] = '\0';
		ft_putstr(buf, 1, size);
		size = read(fd, buf, 4096);
	}
	close(fd);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		ft_putstr("File name missing.\n", 2, 0);
	else if (argc != 2)
		ft_putstr("Too many arguments.\n", 2, 0);
	else
		display_file(argv[1]);
	return (0);
}

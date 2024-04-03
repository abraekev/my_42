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

#include "get_next_line.h"

int	ft_fd(char *filepath)
{
	return (open(filepath, O_RDONLY));
}

int	main(int argc, char **argv)
{
	char	*s;
	int		fd;
	int		fd1;
	int		fd2;
	int		i = -1;

	s = NULL;
	if (argc == 2)
	{
		fd = ft_fd(argv[1]);
		s = get_next_line(fd);
		while (++i < 3)
		{
			printf("%s", s);
			free(s);
			s = get_next_line(fd);
			printf("====LINESEPERATOR====\n");
		}
	}
	else if (argc == 3)
	{
		fd1 = ft_fd(argv[1]);
		fd2 = ft_fd(argv[2]);
		fd = fd1;
		s = get_next_line(fd);
		while (s)
		{
			printf("%s", s);
			free(s);
			if (fd == fd1)
				fd = fd2;
			else
				fd = fd1;
			s = get_next_line(fd);
		}
	}
	else if (argc == 1)
	{
		s = get_next_line(2);
		while (s)
		{
			printf("%s", s);
			free(s);
			s = get_next_line(2);
		}
	}
	else
		printf("Error\n");
	return (0);
}

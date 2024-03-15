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
	size_t	len;
	int		fd;

	if (argc == 2)
	{
		s = NULL;
		fd = ft_fd(argv[1]);
		s = get_next_line(fd);
		while (s)
		{
			printf("%s", s);
			free(s);
			s = get_next_line(fd);
		}
	}
	else if (argc == 1)
		get_next_line(0);
	else
		printf("Error\n");
	return (0);
}

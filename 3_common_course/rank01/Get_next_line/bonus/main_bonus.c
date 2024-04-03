/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:26:59 by abraekev          #+#    #+#             */
/*   Updated: 2024/04/03 14:09:44 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	
	
	printf("main");
	s = NULL;
	if (argc == 2)
	{
		fd = ft_fd(argv[1]);
		while (++i < 2)
		{
			printf("%s", get_next_line(fd));
			printf("====LINESEPERATOR====\n");
		}
	}
	else if (argc == 3)
	{
		fd1 = ft_fd(argv[1]);
		fd2 = ft_fd(argv[2]);
		while (++i< 2)
		{
			printf("%s", get_next_line(fd1));
			printf("====LINESEPERATOR====\n");
		}
		while (++i< 5)
		{
			printf("%s", get_next_line(fd2));
			printf("====LINESEPERATOR====\n");
		}
		while (++i< 8)
		{
			printf("%s", get_next_line(fd1));
			printf("====LINESEPERATOR====\n");
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

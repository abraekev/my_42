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
	
	s = NULL;
	if (argc == 2)
	{
		fd = ft_fd(argv[1]);
		s = get_next_line(fd);
		while (s)
		{
			//printf("|==============\n");
			printf("%s", s);
			//printf("====LINESEPERATOR====\n\n");
			free(s);
			s = get_next_line(fd);
			//printf("|==============\n\n");
		}
	}
	else if (argc == 3)
	{
		fd1 = ft_fd(argv[1]);
		fd2 = ft_fd(argv[2]);
		i = 0;
		while (i< 2)
		{
			printf("|===while1====\n");
			printf("|%s", get_next_line(fd1));
			printf("|===while1====\n\n");
			i++;
		}
		while (i< 4)
		{
			printf("|===while2====\n");
			printf("|%s", get_next_line(fd2));
			printf("|===while2====\n\n");
			i++;
		}
		while (i< 6)
		{
			printf("|===while3====\n");
			printf("|%s", get_next_line(fd1));
			printf("|===while3====\n\n");
			i++;
		}
		while (i< 8)
		{
			printf("|===while4====\n");
			printf("|%s", get_next_line(fd2));
			printf("|===while4====\n\n");
			i++;
		}
		while (i< 10)
		{
			printf("|===while5====\n");
			printf("|%s", get_next_line(fd1));
			printf("|===while5====\n\n");
			i++;
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

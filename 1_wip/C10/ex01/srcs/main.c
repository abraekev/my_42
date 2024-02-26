/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:26:59 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/26 17:06:45 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	error(int i)
{
	if (i < 0)
		i = errno;	
	ft_putstr(strerror(i));
	ft_putstr("\n");
}

/*
void ft_putstr_fd(char *s, int fd)
{
    while (*s)
        write(fd, s++, 1);
}

void print_error(char *filename)
{
    ft_putstr_fd("ft_cat: ", STDERR_FILENO);
    ft_putstr_fd(filename, STDERR_FILENO);
    ft_putstr_fd(": ", STDERR_FILENO);
    ft_putstr_fd(strerror(errno), STDERR_FILENO);
    ft_putstr_fd("\n", STDERR_FILENO);
}
*/

int	main(int argc, char **argv)
{
	char	*test;

	if (argc < 2)
	{
			error(22);		
			return (0);
	}
	test = argv[1];
	printf("==%s==\n", test);
	return (0);
}

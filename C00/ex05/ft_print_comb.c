/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:10:52 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/08 17:02:58 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	char	x;
	char	y;
	char	z;

	x = '0';
	while (x < '8')
	{
		y = x + 1;
		while (y < '9')
		{
			z = y + 1;
			while (z <= '9')
			{
				write (1, &x, 1);
				write (1, &y, 1);
				write (1, &z, 1);
				if (!(x == '7' && y == '8' && z == '9'))
					write (1, ", ", 2);
				z++;
			}
			y++;
		}
		x++;
	}
}
/*
int	main(void)
{
	ft_print_comb();
	return (0);
}
*/

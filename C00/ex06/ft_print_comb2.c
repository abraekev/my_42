/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:56:34 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/08 13:25:06 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2(void)
{
	char	x;
	int		a;
	int		b;

	a = 0;
	while (a != 99)
	{
		b = a + 1;
		while (b <= 99)
		{
			x = '0' + (a / 10);
			write (1, &x, 1);
			x = '0' + (a % 10);
			write (1, &x, 1);
			write (1, " ", 1);
			x = '0' + (b / 10);
			write (1, &x, 1);
			x = '0' + (b % 10);
			write (1, &x, 1);
			if (a != 98)
				write (1, ", ", 2);
			b++;
		}
		a++;
	}	
}
/*
int	main(void)
{
	ft_print_comb2();
	return (0);
}
*/

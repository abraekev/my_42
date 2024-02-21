/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:33:16 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/19 12:17:10 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Create a function
// that displays the number entered as a parameter. The function
// has to be able to display all possible values within an int type variable.

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		if (nb == -2147483648)
		{
			nb = -147483648;
			ft_putchar('2');
		}
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar('0' + (nb % 10));
}	

/*
#include <stdio.h>
#include <string.h>
#include <limits.h>

int	main(void)
{
	ft_putnbr(2147483647);
	ft_putnbr(-2147483648);
	return (0);
}
*/

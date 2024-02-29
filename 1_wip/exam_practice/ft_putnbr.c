/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 09:32:25 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/29 11:34:29 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>

void	ft_putnbr(int nb)
{
	int		i;
	char	c;

	if (nb == INT_MIN)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = - nb;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	c = '0' + (nb % 10);
	write(1, &c, 1);
}

int	ft_atoi(char *str)
{
	int		i;
	int		sign;
	long	l;
	int 	nb;

	i = 0;
	sign = 1;
	l = 0;
	if (!str)
		return (0);	
	while (str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{	
		l =(l * 10) + (str[i] - '0');
		i++;
	}
	i = (int)l;
	if (i == l)	
		return (sign * i);
	return (0);
}

#include <stdio.h>
int	main(int argc, char **argv)
{
	printf("=%d=\n", INT_MIN);
	
	ft_putnbr(ft_atoi(argv[1]));
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:14:07 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/27 17:44:26 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putspecial(int c, int firstdigit)
{
	char	*base;
	int		rest;

	base = "0123456789abcdef";
	if (c / 16 >= 16)
		ft_putspecial(c / 16, 0);
	rest = c % 16;
	if (firstdigit)
		ft_putchar('0');
	ft_putchar(base[rest]);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;
	int	c;

	i = 0;
	while (str[i])
	{
		if (str[i] < 32 || str[i] == 127)
		{
			ft_putchar('\\');
			c = str[i];
			ft_putspecial(c, 1);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}
/*
int	main(void)
{
	ft_putstr_non_printable("Coucou 		tu vas bien ?");
	return 0;
}
*/

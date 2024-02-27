/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   only_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:44:56 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/27 15:15:09 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	arg_valid_bytes(char *str)
{
	long	nb;
	int		min;
	int		res;

	nb = 0;
	min = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\r' || *str == '\f' || *str == '\v')
		str ++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			min *= -1;
		str ++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nb = (nb * 10) + (*str - '0');
		str++;
	}
	res = nb;
	if (res != nb)
		return (0);
	return (min * nb);
}

void	only_c(char **argv)
{
	ft_error(basename(argv[0]));
	ft_error(": option requires an argument -- \'c\'\n");
	ft_error("Try \'tail --help\' for more information.\n");
}

void	invalid_byte(char **argv)
{
	ft_error(basename(argv[0]));
	ft_error(": invalid number of bytes: \u2018");
	ft_error(argv[2]);
	ft_error("\u2019\n");
}

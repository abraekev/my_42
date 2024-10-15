/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_int_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:52:07 by abraekev          #+#    #+#             */
/*   Updated: 2024/10/15 14:04:52 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_white_space(const char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r')
		return (1);
	return (0);
}

static int	is_long_overflow(long nb, char c, int min)
{
	if (min == 1 && (nb > LONG_MAX / 10 || (nb == LONG_MAX / 10 && c
				- '0' > LONG_MAX % 10)))
		return (1);
	if (min == -1 && (nb > -(LONG_MIN / 10) || (nb == -(LONG_MIN / 10) && c
				- '0' > -(LONG_MIN % 10))))
		return (1);
	return (0);
}

int	is_valid_int_string(const char *str)
{
	unsigned int	i;
	int				min;
	long			nb;

	nb = 0;
	min = 1;
	i = 0;
	while (is_white_space(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			min = -1;
	if (!str[i])
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (is_long_overflow(nb, str[i], min))
			return (0);
		nb = (nb * 10) + (str[i++] - '0');
	}
	while (is_white_space(str[i]))
		i++;
	if (str[i])
		return (0);
	return (1);
}

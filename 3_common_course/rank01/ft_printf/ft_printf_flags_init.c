/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags_init.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:58:41 by abraekev          #+#    #+#             */
/*   Updated: 2024/03/17 17:22:21 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

// char *fspec = %[flags][min width][precision][conv specifier]

int	validate_flags(char *s, t_flags *flags)
{
	size_t		i;

	i = 1;
	if (s[i] == '%')
		return (1);
	while (ft_strchr("#0- +", s[i]))
		i++;
	while ((s[i] >= '1' && s[i] <= '9') || s[i] == '*')
	{
		if (s[i] == '*')
			break ;
		i++;
	}
	if (s[i] == '.')
	{
		i++;
		if (s[i] == '-')
			i++;
		while (ft_isdigit(s[i]))
			i++;
	}
	if (ft_strchr("cspdiuxX", s[i]) && !s[i + 1])
		return (1);
	return (0);
}

t_flags	initiate_flags(void)
{
	t_flags	flags;

	flags.just_l = 0;
	flags.pad_zero = 0;
	flags.pref_space = 0;
	flags.pref_plus = 0;
	flags.alt_print = 0;
	flags.min_width = 0;
	flags.precision = -1;
	flags.cspec = 0;
	return (flags);
}

void	get_precision(t_flags *flags, char *fspec)
{
	int	i;
	int	nbr;

	i = 0;
	while (fspec[i] && fspec[i] != '.')
		i++;
	i++;
	nbr = ft_atoi((fspec + i));
	if (nbr)
		flags->precision = nbr;
	else if (!nbr && fspec[i] == '0')
		flags->precision = 0;
	else
		flags->precision = -1;
}

void	get_min_width(t_flags *flags, char *fspec)
{
	int	i;
	int	nbr;

	i = 0;
	while (fspec[i] && (fspec[i] < '1' || fspec[i] > '9'))
	{
		if (fspec[i] == '.')
			return ;
		i++;
	}
	nbr = ft_atoi((fspec + i));
	if (nbr)
		flags->min_width = nbr;
}

int	getflags(char *fspec, t_flags *flags)
{
	if (!validate_flags(fspec, flags))
		return (0);
	if (ft_strchr(fspec, '-'))
		flags->just_l = 1;
	if (ft_strchr(fspec, '0'))
		flags->pad_zero = 1;
	if (ft_strchr(fspec, ' '))
		flags->pref_space = 1;
	if (ft_strchr(fspec, '+'))
		flags->pref_plus = 1;
	flags->cspec = fspec[ft_strlen(fspec) - 1];
	get_min_width(flags, fspec);
	get_precision(flags, fspec);
	return (1);
}

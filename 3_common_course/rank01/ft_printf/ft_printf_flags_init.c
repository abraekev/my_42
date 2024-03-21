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

t_flags	initiate_flags(void)
{
	t_flags	flags;

	flags.just_l = 0;
	flags.pad_zero = 0;
	flags.pref_space = 0;
	flags.pref_plus = 0;
	flags.alt_print = 0;
	flags.min_width = 0;
	flags.precision = 0;
	flags.cspec = 0;
	return (flags);
}

void	get_precision(t_flags *flags, char *fspec)
{
	int		i;

	i = 0;
	while (fspec[i] && fspec[i] != '.')
		i++;
	while (fspec[i])
	{
		if (ft_isdigit(fspec[i]))
		{
			flags->precision = ((flags->precision) * 10
					+ (fspec[i] - '0'));
			if (!ft_isdigit(fspec[i + 1]))
				break ;
		}
		i++;
	}
}

void	get_min_width(t_flags *flags, char *fspec)
{
	int		i;

	i = -1;
	while (fspec[++i])
	{
		if (flags->min_width == 0 && fspec[i] == '0')
			continue ;
		if (fspec[i] == '.')
			break ;
		if (ft_isdigit(fspec[i]))
		{
			flags->min_width = ((flags->min_width) * 10
					+ (fspec[i] - '0'));
			if (!ft_isdigit(fspec[i + 1]))
				break ;
		}
	}
}

t_flags	getflags(char *fspec)
{
	t_flags	flags;

	flags = initiate_flags();
	if (ft_strchr(fspec, '-'))
		flags.just_l = 1;
	if (ft_strchr(fspec, '0'))
		flags.pad_zero = 1;
	if (ft_strchr(fspec, ' '))
		flags.pref_space = 1;
	if (ft_strchr(fspec, '+'))
		flags.pref_plus = 1;
	flags.cspec = fspec[ft_strlen(fspec) - 1];
	get_min_width(&flags, fspec);
	get_precision(&flags, fspec);
	return (flags);
}

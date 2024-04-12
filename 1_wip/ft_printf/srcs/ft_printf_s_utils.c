/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s_utils.c                                :+:      :+:    :+:   */
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

void	ft_putstr_special(t_data *d)
{
	size_t	i;

	i = 0;
	while (i < d->i_len)
		ft_putchar_fd(d->insert[i++], 1);
}

void	free_strs(size_t n, ...)
{
	size_t	i;
	char	**s;
	va_list	args;

	va_start(args, n);
	i = 0;
	while (i < n)
	{
		s = va_arg(args, char **);
		if (s && *s)
		{
			free(*s);
			*s = NULL;
		}
		i++;
	}
	return ;
}

void	free_data(t_data *d)
{
	if (d && d->fspec)
	{
		free(d->fspec);
		d->fspec = NULL;
	}
	if (d && d->insert)
	{
		free(d->insert);
		d->insert = NULL;
	}
	return ;
}

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

char	*update_s(t_data *d, size_t i)
{
	char	*tmp;
	char	*out;

	tmp = ft_substr(d->s, 0, i);
	if (!tmp)
		return (NULL);
	out = ft_strjoin(tmp, d->insert);
	free(tmp);
	if (!out)
		return (NULL);
	tmp = out;
	out = ft_strjoin(tmp, (d->s + i + d->f_len));
	free(tmp);
	if (!out)
		return (NULL);
	d->s_len = d->s_len - d->f_len + d->i_len + d->add_special;
	return (out);
}

int	zero_freestrs(size_t n, ...)
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
	return (0);
}

char	*null_freestrs(size_t n, ...)
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
	return (NULL);
}

int	ret_int_and_free_d(int nb, t_data *d)
{
	if (d && d->s)
	{
		free(d->s);
		d->s = NULL;
	}
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
	return (nb);
}

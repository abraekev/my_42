/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:58:41 by abraekev          #+#    #+#             */
/*   Updated: 2024/03/17 17:22:21 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

//	format specifier:
//	char *fspec = %[flags][min width][precision][conversion specifier]

static char	*get_fspecstr(t_data *d, size_t i)
{
	char	*convspecs;
	char	*lastchr;
	size_t	j;

	convspecs = "cspdiuxX%";
	j = i + 1;
	while (d->s[j])
	{
		if (ft_strchr(convspecs, d->s[j]))
		{
			lastchr = d->s + j;
			return (ft_substr(d->s, i, (lastchr - (d->s + i) + 1)));
		}
		j++;
	}
	return (NULL);
}

static int	process_formatspec(t_data *d, int i, va_list args)
{
	char	*tmp;

	d->fspec = get_fspecstr(d, i);
	if (!d->fspec)
		return (0);
	d->f_len = ft_strlen(d->fspec);
	d->cspec = d->fspec[d->f_len - 1];
	d->insert = get_insertstr(d, args);
	if (!d->insert)
		return (zero_freestrs(1, d->fspec));
	tmp = update_s(d, i);
	free(d->s);
	if (!tmp)
		return (zero_freestrs(2, d->fspec, d->insert));
	d->s = tmp;
	zero_freestrs(2, d->fspec, d->insert);
	return (d->f_len);
}

static int	create_s(const char *src, t_data *d)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	d->s_len = src_len;
	d->s = malloc(src_len + 1);
	if (!(d->s))
		return (0);
	ft_strlcpy(d->s, src, src_len + 1);
	return (1);
}

static int	get_len_and_print(t_data *d)
{
	if (d->s)
	{
		ft_putstr_fd(d->s, 1);
		free(d->s);
		return (d->s_len);
	}
	else
		return (-1);
}

int	ft_printf(const char *src, ...)
{
	t_data		d;
	size_t		i;
	size_t		jump;
	va_list		args;

	va_start(args, src);
	i = -1;
	if (!create_s(src, &d))
		return (-1);
	while (d.s[++i])
	{
		if (d.s[i] == '%')
		{
			jump = process_formatspec(&d, i, args);
			if (!jump)
			{
				if (d.s)
					free(d.s);
				return (-1);
			}
			i = i + jump - 2;
		}
	}
	return (get_len_and_print(&d));
}

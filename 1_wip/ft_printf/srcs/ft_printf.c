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
			break ;
		j++;
	}
	lastchr = d->s + j;
	return (ft_substr(d->s, i, (lastchr - (d->s + i) + 1)));
}

static int	process_formatspec(t_data *d, int i, va_list args)
{
	char	*tmp;

	d->add_special = 0;
	d->fspec = get_fspecstr(d, i);
	if (!d->fspec)
		return (-1);
	d->f_len = ft_strlen(d->fspec);
	d->cspec = d->fspec[d->f_len - 1];
	d->insert = get_insertstr(d, args);
	if (!d->insert)
		return (-1);
	tmp = update_s(d, i);
	free(d->s);
	if (!tmp)
		return (-1);
	d->s = tmp;
	null_freestrs(2, &(d->fspec), &(d->insert));
	return (d->i_len);
}

static int	init_d(const char *src, t_data *d)
{
	d->s_len = ft_strlen(src);
	d->s = malloc(d->s_len + 1);
	if (!(d->s))
		return (0);
	ft_strlcpy(d->s, src, d->s_len + 1);
	d->add_special = 0;
	d->cspec = 0;
	d->f_len = 0;
	d->i_len = 0;
	d->fspec = NULL;
	d->insert = NULL;
	return (1);
}

static int	get_len_and_print(t_data *d)
{
	if (d->s)
	{
		printf(">%lu<\n", d->s_len);
		printf(">%lu<\n", ft_strlen(d->s));
		ft_putstr_fd(d->s, 1);
		ret_int_and_free_d(1, d);
		return (d->s_len);
	}
	else
		return (ret_int_and_free_d(-1, d));
}

int	ft_printf(const char *src, ...)
{
	t_data		d;
	size_t		i;
	int			jump;
	va_list		args;

	va_start(args, src);
	i = 0;
	if (!init_d(src, &d))
		return (-1);
	while (d.s[i])
	{
		if (d.s[i] == '%')
		{
			jump = process_formatspec(&d, i, args);
			if (jump < 0)
				return (ret_int_and_free_d(-1, &d));
			i = i + jump;
		}
		else
			i++;
	}
	return (get_len_and_print(&d));
}

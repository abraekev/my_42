/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_gets.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:58:41 by abraekev          #+#    #+#             */
/*   Updated: 2024/03/17 17:22:21 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	*get_char(char c)
{
	char	*s;

	s = malloc(2);
	if (!s)
		return (NULL);
	s[0] = c;
	s[1] = 0;
	return (s);
}

char	*get_str(char *s)
{
	char	*out;
	size_t	o_len;

	if (!s)
		return (NULL);
	else
	{
		o_len = ft_strlen(s);
		out = malloc(o_len + 1);
		if (!out)
			return (NULL);
		ft_strlcpy(out, s, o_len + 1);
	}
	return (out);
}

char	*apply_flags(t_flags f, t_data *d)
{
	set_i_len(d);
	if (ft_strchr("sdiuxX", f.cspec))
		d->insert = apply_precision(d, f);
	set_i_len(d);
	if (ft_strchr("di", f.cspec))
		d->insert = apply_spaceplus(d, f);
	set_i_len(d);
	if (ft_strchr("xX", f.cspec))
		d->insert = apply_altprint(d, f);
	set_i_len(d);
	if (ft_strchr("cspdiuxX", f.cspec))
		d->insert = apply_width_others(d, f);
	set_s_len(d);
	return (d->insert);
}

char	*get_insertstr(t_data *d, va_list args)
{
	t_flags	flags;

	flags = initiate_flags();
	if (!get_flags(d->fspec, &flags))
	{
		d->insert = ft_strdup(d->fspec);
		set_lengths(d);
		return (d->insert);
	}
	d->insert = NULL;
	if (d->cspec == '%')
		d->insert = get_char('%');
	if (d->cspec == 'c')
		d->insert = get_char(va_arg(args, int));
	if (d->cspec == 's')
		d->insert = get_str(va_arg(args, char *));
	if (d->cspec == 'd' || d->cspec == 'i')
		d->insert = ft_itoa(va_arg(args, int));
	if (d->cspec == 'p')
		d->insert = get_vptr_base(va_arg(args, uintptr_t), d);
	if (d->cspec == 'u' || d->cspec == 'x' || d->cspec == 'X')
		d->insert = get_uint_base(va_arg(args, unsigned int), d->cspec);
	return (apply_flags(flags, d));
}

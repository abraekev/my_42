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
	{
		out = malloc(7);
		if (!out)
			return (NULL);
		ft_strlcpy(out, "(null)", 7);
	}
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

static void	set_insert_len(char *s, t_data *d)
{
	d->i_len = ft_strlen(s);
	if (d->cspec == 'c' && !ft_strlen(s))
		d->i_len = 1;
}

char	*apply_flags(char *s, t_flags f, t_data *d)
{
	if (ft_strchr("sdiuxX", f.cspec))
		s = apply_precision(s, f);
	if (ft_strchr("di", f.cspec))
		s = apply_spaceplus(s, f);
	if (ft_strchr("xX", f.cspec))
		s = apply_altprint(s, f);
	if (ft_strchr("cspdiuxX", f.cspec))
		s = apply_width_others(s, f);
	set_insert_len(s, d);
	return (s);
}

char	*get_insertstr(t_data *d, va_list args)
{
	t_flags	flags;
	char	*out;

	flags = initiate_flags();
	if (!get_flags(d->fspec, &flags))
		return (d->fspec);
	out = NULL;
	if (d->cspec == '%')
		out = get_char('%');
	if (d->cspec == 'c')
		out = get_char(va_arg(args, int));
	if (d->cspec == 's')
		out = get_str(va_arg(args, char *));
	if (d->cspec == 'd' || d->cspec == 'i')
		out = ft_itoa(va_arg(args, int));
	if (d->cspec == 'p')
		out = get_vptr_base(va_arg(args, uintptr_t));
	if (d->cspec == 'u' || d->cspec == 'x' || d->cspec == 'X')
		out = get_uint_base(va_arg(args, unsigned int), d->cspec);
	return (apply_flags(out, flags, d));
}

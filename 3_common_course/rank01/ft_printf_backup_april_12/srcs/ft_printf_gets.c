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

// special case if %c and its the 0 terminator
static void	set_lengths(char *insert, t_data *d)
{
	d->i_len = ft_strlen(insert);
	if (!d->i_len && d->cspec == 'c')
		d->i_len++;
	d->s_len = d->s_len - d->f_len + d->i_len;
}

char	*apply_flags(char *insert, t_flags f, t_data *d)
{
	if (ft_strchr("sdiuxX", f.cspec))
		insert = apply_precision(insert, f);
	if (ft_strchr("di", f.cspec))
		insert = apply_spaceplus(insert, f);
	if (ft_strchr("xX", f.cspec))
		insert = apply_altprint(insert, f);
	if (ft_strchr("cspdiuxX", f.cspec))
		insert = apply_width_others(insert, f);
	set_lengths(insert, d);
	return (insert);
}

char	*get_insertstr(t_data *d, va_list args)
{
	t_flags	flags;
	char	*insert;

	flags = initiate_flags();
	if (!get_flags(d->fspec, &flags))
	{
		insert = ft_strdup(d->fspec);
		set_lengths(insert, d);
		return (insert);
	}
	insert = NULL;
	if (d->cspec == '%')
		insert = get_char('%');
	if (d->cspec == 'c')
		insert = get_char(va_arg(args, int));
	if (d->cspec == 's')
		insert = get_str(va_arg(args, char *));
	if (d->cspec == 'd' || d->cspec == 'i')
		insert = ft_itoa(va_arg(args, int));
	if (d->cspec == 'p')
		insert = get_vptr_base(va_arg(args, uintptr_t));
	if (d->cspec == 'u' || d->cspec == 'x' || d->cspec == 'X')
		insert = get_uint_base(va_arg(args, unsigned int), d->cspec);
	return (apply_flags(insert, flags, d));
}

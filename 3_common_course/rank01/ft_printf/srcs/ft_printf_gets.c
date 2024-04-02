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

/*
char *fspec = %[flags][min width][precision][conv specifier]

typedef struct s_flags
{
	char	cspec;
	int		just_l;
	int		pad_zero;
	int		pref_space;
	int		pref_plus;
	int		alt_print;
	int		min_width;
	int		precision;
}	t_flags;
*/

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

	o_len = ft_strlen(s);
	out = malloc(o_len + 1);
	if (!out)
		return (NULL);
	ft_strlcpy(out, s, o_len + 1);
	return (out);
}

char	*apply_flags(char *s, t_flags f)
{
	if (ft_strchr("sdiuxX", f.cspec))
		s = apply_precision(s, f);
	if (ft_strchr("di", f.cspec))
		s = apply_spaceplus(s, f);
	if (ft_strchr("xX", f.cspec))
		s = apply_altprint(s, f);
	if (ft_strchr("cspdiuxX", f.cspec))
		s = apply_width_others(s, f);
	return (s);
}

char	*get_insertstr(char *fspec, va_list args, char cspec)
{
	t_flags	flags;
	char	*out;

	flags = initiate_flags();
	if (!get_flags(fspec, &flags))
		return (fspec);
	out = NULL;
	if (cspec == '%')
		out = get_char('%');
	if (cspec == 'c')
		out = get_char(va_arg(args, int));
	if (cspec == 's')
		out = get_str(va_arg(args, char *));
	if (cspec == 'd' || cspec == 'i')
		out = ft_itoa(va_arg(args, int));
	if (cspec == 'p')
		out = get_vptr_base(va_arg(args, uintptr_t));
	if (cspec == 'u' || cspec == 'x' || cspec == 'X')
		out = get_uint_base(va_arg(args, unsigned int), cspec);
	return (apply_flags(out, flags));
}

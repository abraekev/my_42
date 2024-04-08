/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_apply_prec.c                             :+:      :+:    :+:   */
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

static char	*apply_precision_specialcase(char *s)
{
	char	*tmp;

	free(s);
	tmp = malloc(1);
	if (!tmp)
		return (NULL);
	tmp[0] = 0;
	return (tmp);
}

static int	apply_precision_negative(char **tmp, char *s)
{
	char	*tmp2;

	tmp2 = ft_strjoin("-", *tmp);
	if (!tmp2)
		return (zero_freestrs(2, &s, tmp));
	free(*tmp);
	*tmp = tmp2;
	return (1);
}

static int	apply_prec_nbr_newstr(char **s, char *abs, int len)
{
	char	*tmp;
	char	*tmp2;

	tmp = malloc(len + 1);
	if (!tmp)
		return (zero_freestrs(1, s));
	tmp[len] = 0;
	while (--len >= 0)
		tmp[len] = '0';
	if (**s == '-')
		if (!apply_precision_negative(&tmp, *s))
			return (0);
	tmp2 = ft_strjoin(tmp, abs);
	if (!tmp)
		return (zero_freestrs(2, s, &tmp));
	zero_freestrs(2, s, &tmp);
	*s = tmp2;
	return (1);
}

static char	*apply_precision_nbr(char *s, t_flags f)
{
	char	*abs;
	int		len;

	if (*s == '0' && f.precision == 0)
		return (apply_precision_specialcase(s));
	abs = s;
	if (*s == '-')
		abs = s + 1;
	len = (size_t)f.precision - ft_strlen(abs);
	if (len > 0)
		if (!apply_prec_nbr_newstr(&s, abs, len))
			return (NULL);
	return (s);
}

//	only for: s or diuxX
char	*apply_precision(char *s, t_flags f)
{
	char	*tmp;

	if (!s)
		return (NULL);
	if (f.precision < 0)
		return (s);
	if (f.cspec == 's')
	{
		if ((size_t)f.precision < ft_strlen(s))
		{
			tmp = malloc(f.precision + 1);
			if (!tmp)
				return (null_freestrs(1, &s));
			ft_strlcpy(tmp, s, f.precision + 1);
			free(s);
			return (tmp);
		}
		return (s);
	}
	else
		return (apply_precision_nbr(s, f));
}

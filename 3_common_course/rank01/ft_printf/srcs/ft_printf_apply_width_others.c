/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_apply_width_others.c                     :+:      :+:    :+:   */
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

static void	fill_str(char *s, size_t len, char c)
{
	s[len] = 0;
	while (--len != UINT_MAX)
	{
		s[len] = c;
		if (!len)
			break ;
	}
}

static char	*apply_join(char *s, t_flags f, char *add)
{
	char	*out;

	if (f.just_l)
		out = ft_strjoin(s, add);
	else
		out = ft_strjoin(add, s);
	free_strs(2, &add, &s);
	return (out);
}

char	*apply_width_others(char *s, t_flags f)
{
	char	*add;
	size_t	a_len;

	if (!s)
		return (NULL);
	if ((unsigned int)f.min_width <= ft_strlen(s))
		return (s);
	a_len = f.min_width - ft_strlen(s);
	add = malloc(a_len + 1);
	if (!add)
		return (free_strs(1, &s), NULL);
	if (f.pad_zero && !f.just_l && f.precision < 0
		&& ft_strchr("diuxX", f.cspec))
		fill_str(add, a_len, '0');
	else
		fill_str(add, a_len, ' ');
	return (apply_join(s, f, add));
}

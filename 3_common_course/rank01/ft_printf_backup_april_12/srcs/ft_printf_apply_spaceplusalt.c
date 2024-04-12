/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_apply_spaceplusalt.c                     :+:      :+:    :+:   */
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
	int		pref_space;
	int		pref_plus;
*/
char	*add_prefix(char *s, char *prefix)
{
	char	*out;

	if (!s)
		return (NULL);
	if (*s == '-')
		return (s);
	out = ft_strjoin(prefix, s);
	free(s);
	if (!out)
		return (NULL);
	return (out);
}

char	*apply_spaceplus(char *s, t_flags f)
{
	if (!s)
		return (NULL);
	if (f.pref_space && !f.pref_plus)
		return (add_prefix(s, " "));
	if (f.pref_plus)
		return (add_prefix(s, "+"));
	return (s);
}

char	*apply_altprint(char *s, t_flags f)
{
	if (!s)
		return (NULL);
	if (!f.alt_print)
		return (s);
	if (f.cspec == 'x')
		return (add_prefix(s, "0x"));
	else
		return (add_prefix(s, "0X"));
}

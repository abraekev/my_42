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

// char *fspec = %[flags][min width][precision][conv specifier]

char	*get_char(char *fspec, char c)
{
	return (NULL);
}

char	*get_percent(void)
{
	char	*out;

	out = malloc(2);
	if (!out)
		return (NULL);
	ft_strlcpy(out, "%", 2);
	return (out);
}

char	*get_insertstr(char *fspec, va_list args, char convspec)
{
	t_flags	flags;

	flags = getflags(fspec);
	if (convspec == '%')
		return (get_percent());
	if (convspec == 'c')
		return (get_char(fspec, va_arg(args, int)));
	if (convspec == 's')
		return (NULL);
	if (convspec == 'd' || convspec == 'i')
		return (NULL);
	if (convspec == 'p')
		return (NULL);
	if (convspec == 'u' || convspec == 'x' || convspec == 'X')
		return (NULL);
	return (NULL);
}

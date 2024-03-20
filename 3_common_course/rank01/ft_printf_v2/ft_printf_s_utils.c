/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s_utils.c                                :+:      :+:    :+:   */
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

char	*update_s(char *s, char *insert, size_t i, size_t fspec_len)
{
	char	*tmp;
	char	*out;

	tmp = ft_substr(s, 0, i);
	if (!tmp)
		return (NULL);
	out = ft_strjoin(tmp, insert);
	free(tmp);
	if (!out)
		return (NULL);
	tmp = out;
	out = ft_strjoin(tmp, (s + i + fspec_len));
	free(tmp);
	if (!out)
		return (NULL);
	return (out);
}

int	null_freestrs(size_t n, ...)
{
	size_t	i;
	va_list	args;

	va_start(args, n);
	i = 0;
	while (i < n)
	{
		free(va_arg(args, char *));
		i++;
	}
	return (0);
}

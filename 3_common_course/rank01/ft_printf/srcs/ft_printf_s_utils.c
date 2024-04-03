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

char	*update_s(t_data *d, size_t i)
{
	char	*tmp;
	char	*out;

	tmp = ft_substr(d->s, 0, i);
	if (!tmp)
		return (NULL);
	out = ft_strjoin(tmp, d->insert);
	free(tmp);
	if (!out)
		return (NULL);
	tmp = out;
	out = ft_strjoin(tmp, (d->s + i + d->f_len));
	free(tmp);
	if (!out)
		return (NULL);
	d->s_len = d->s_len - d->f_len + d->i_len;
	return (out);
}

char	*null_freestrs(size_t n, ...)
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
	return (NULL);
}

int	zero_freestrs(size_t n, ...)
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

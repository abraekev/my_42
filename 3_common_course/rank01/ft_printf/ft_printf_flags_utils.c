/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags_init.c                             :+:      :+:    :+:   */
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

char	*get_alt_print(char *s)
{
	size_t	s_len;
	char	*out;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	out = malloc(s_len + 3);
	ft_strlcpy(out, "0x", s_len + 3);
	ft_strlcat(out, s ,s_len + 3);
	free(s);
	return (out);
}

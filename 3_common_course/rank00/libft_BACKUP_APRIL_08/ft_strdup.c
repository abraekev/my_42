/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:12:52 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/27 17:45:49 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char		*out;
	size_t		i;
	size_t		len;

	len = ft_strlen(s);
	out = malloc(len + 1);
	if (!out)
		return (NULL);
	i = -1;
	while (++i < len)
		out[i] = s[i];
	out[i] = 0;
	return (out);
}

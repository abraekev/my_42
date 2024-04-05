/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:58:41 by abraekev          #+#    #+#             */
/*   Updated: 2024/04/05 13:23:46 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*(s++))
		i++;
	return (i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*out;
	size_t			total;
	size_t			i;

	if (nmemb && size > (SIZE_MAX / nmemb))
		return (NULL);
	total = nmemb * size;
	out = malloc(total);
	if (!out)
		return (NULL);
	i = 0;
	while (total > 0 && i < total)
		out[i++] = 0;
	return ((void *)out);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str)
	{
		if (*str == c)
			return (str);
		str++;
	}
	if (c == 0)
		return (str);
	return (NULL);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t d_size)
{
	size_t	i;
	size_t	s_len;

	i = 0;
	if (!src)
		return (0);
	s_len = ft_strlen(src);
	if (!d_size)
		return (s_len);
	while (src[i] && i < d_size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (s_len);
}

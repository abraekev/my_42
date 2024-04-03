/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:58:41 by abraekev          #+#    #+#             */
/*   Updated: 2024/04/03 14:09:28 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*(s++))
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*out;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		out = malloc(1);
		if (!out)
			return (NULL);
		out[0] = 0;
		return (out);
	}
	if (start + len > s_len)
		len = s_len - start;
	out = malloc(len + 1);
	if (!out)
		return (NULL);
	i = -1;
	while (++i < len)
		out[i] = s[start + i];
	out[i] = 0;
	return (out);
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

size_t	ft_strlcat(char *dest, const char *src, size_t d_size)
{
	size_t	i;
	size_t	d_len;
	size_t	s_len;

	i = 0;
	d_len = ft_strlen(dest);
	s_len = ft_strlen(src);
	if (!d_size)
		return (s_len);
	while (src[i] && d_len + i < d_size - 1)
	{
		dest[d_len + i] = src[i];
		i++;
	}
	dest[d_len + i] = 0;
	if (d_size < d_len)
		return (d_size + s_len);
	return (d_len + s_len);
}

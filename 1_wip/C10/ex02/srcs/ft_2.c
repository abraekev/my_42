/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 09:08:27 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/26 17:28:12 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_is_charset(char c, char *charset)
{
	int	i;

	i = -1;
	while (charset[++i])
	{
		if (c == charset[i])
			return (1);
	}
	return (0);
}

int	ft_get_length_out(char *str, char *charset)
{
	int	length;
	int	i;

	length = 0;
	i = 0;
	while (str[i])
	{
		if (!ft_is_charset(str[i], charset))
			length++;
		while (str[i] && !ft_is_charset(str[i], charset))
			i++;
		while (str[i] && ft_is_charset(str[i], charset))
			i++;
	}
	return (length);
}

int	ft_split_create_str(char **out, char *str, int strlength, int i)
{
	int	j;
	int	strt_str;

	strt_str = i - strlength;
	j = 0;
	while (out[j])
		j++;
	out [j] = malloc(strlength + 1);
	if (!out[j])
	{
		free(out[j]);
		while (--j >= 0)
			free(out[j]);
		free(out);
		return (0);
	}
	i = -1;
	while (++i < strlength)
	{
		(out[j])[i] = str[strt_str + i];
	}
	(out[j])[i] = 0;
	return (1);
}

int	ft_split_read_strs(char **out, char *str, char *charset)
{
	int	strlength;
	int	i;

	i = 0;
	while (str[i])
	{
		strlength = 0;
		while (str[i] && !ft_is_charset(str[i], charset))
		{
			strlength ++;
			i++;
		}
		if (strlength)
			if (!(ft_split_create_str(out, str, strlength, i)))
				return (0);
		while (str[i] && ft_is_charset(str[i], charset))
			i++;
	}
	return (1);
}

char	**ft_split(char *str, char *charset)
{
	char		**out;
	int			length;
	int			i;

	length = ft_get_length_out(str, charset) + 1;
	out = malloc(sizeof(char *) * length);
	if (!out)
		return (NULL);
	i = -1;
	while (++i < length)
		out[i] = 0;
	if (!(ft_split_read_strs(out, str, charset)))
		return (NULL);
	return (out);
}

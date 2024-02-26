/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:50:23 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/25 15:31:12 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"
#include <unistd.h>
#include <stdlib.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (*(src + i) != '\0')
	{
		*(dest + i) = *(src + i);
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strjoin_len(int size, char **strs, char *sep)
{
	int	i;
	int	size_out;

	i = -1;
	size_out = 0;
	while (++i < size)
	{
		size_out += ft_strlen(strs[i]);
		if (i < (size - 1))
			size_out += ft_strlen(sep);
	}
	return (size_out);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*out;
	int		size_out;
	int		i;

	if (size == 0)
	{
		out = malloc(1);
		return (out);
	}
	i = -1;
	size_out = ft_strjoin_len(size, strs, sep);
	out = malloc(size_out + 1);
	ft_strcpy(out, "");
	i = -1;
	while (++i < size)
	{
		out = ft_strcat(out, strs[i]);
		if ((i < size - 1))
			out = ft_strcat(out, sep);
	}
	return (out);
}

char	*ft_strstr(char *str, char *to_find)
{
	char	*begin_to_find;
	int		teller;

	teller = 0;
	begin_to_find = to_find;
	while (*to_find != '\0' && *str != '\0')
	{
		if (*str == *to_find)
		{
			str++;
			to_find++;
			teller++;
		}
		else
		{
			str++;
			to_find = begin_to_find;
			teller = 0;
		}
	}
	if (*to_find == '\0')
		return (str - teller);
	else
		return (0);
}

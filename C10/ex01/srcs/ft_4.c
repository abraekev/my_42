/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:40:53 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/20 09:34:36 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

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

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (*s1 == '\0' && *s2 == '\0')
		return (0);
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if (s1[i] - s2[i] != 0)
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
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

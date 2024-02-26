/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:50:23 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/24 20:17:07 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	teller;

	teller = 0;
	while (*str != 0)
	{
		str++;
		teller++;
	}
	return (teller);
}

char	*ft_strcat(char *dest, char *src)
{
	char	*output;

	output = dest;
	while (*dest != '\0')
	{
		dest ++;
	}
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (output);
}

int	ft_strcmp(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (0);
	while (*s1 != '\0' || *s2 != '\0')
	{
		if (*s1 - *s2 != 0)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str != 0)
	{
		ft_putchar(*str);
		str++;
	}
}

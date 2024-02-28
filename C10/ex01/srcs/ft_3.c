/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:01:06 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/13 10:04:42 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

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

char	*ft_strcpy(char *dest, char *src)
{
	char	*loop;

	loop = dest;
	while (*src != '\0')
	{
		*loop = *src;
		src++;
		loop++;
	}
	*loop = '\0';
	return (dest);
}

int	ft_strlen(char *src)
{
	int	c;

	c = 0;
	while (*src != 0)
	{
		src++;
		c++;
	}
	return (c);
}

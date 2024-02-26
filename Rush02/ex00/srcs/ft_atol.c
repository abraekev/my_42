/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-roec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 16:47:03 by bde-roec          #+#    #+#             */
/*   Updated: 2024/02/25 10:54:40 by bde-roec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"
#include <stdio.h>

int	*ft_atol(char *src)
{
	int				i;
	unsigned long	l_value;
	unsigned int	value;	

	l_value = 0;
	value = 0;
	i = 0;
	while (src[i] != '\0')
	{
		l_value *= 10;
		l_value += (src[i] - '0');
		i++;
	}
	return (cut_int(l_value));
}
/*
int	main(void)
{
	char *stri = "4294967295";
	char *stri2 = "0";
	char *stri3 = "4294967296";

	printf("value = %u\n",ft_atol(stri));
	printf("value = %u\n",ft_atol(stri2));
	printf("value = %u\n",ft_atol(stri3));
	return (0);
}
*/

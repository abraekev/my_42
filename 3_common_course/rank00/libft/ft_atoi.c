/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:48:35 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/29 13:57:15 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_white_space(const char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	unsigned int	i;
	int				out;
	int				min;
	long			nb;

	nb = 0;
	min = 1;
	i = 0;
	while (is_white_space(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			min = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	out = (int)(min * nb);
	if (out == min * nb)
		return (out);
	return (0);
}

/*
#include <unistd.h>
#include <strings.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{

	char *str1 = "-2147483648";
	char *str2 = "2147483647";
	char *str3 = " -333rdd 0";
	char *str4 = "2147483647mmmm";
	char *str5 = "9999999999999999993999";
	char *str6 = "   -+-666gertg";
	char *array[]={str1, str2, str3, str4, str5, str6};

	for (int i = 0; i <= 5; i++)
	{
		printf("str:\t\"%s\"\nft_:\t%d\n", array[i], ft_atoi(array[i]));
		printf("lib:\t%d\n\n", atoi(array[i]));
	}
	return (0);
}
*/

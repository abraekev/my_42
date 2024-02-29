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

int	ft_atoi(char *str)
{
	int	nb;
	int	min;

	nb = 0;
	min = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\r' || *str == '\f' || *str == '\v')
		str ++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			min *= -1;
		str ++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nb = (nb * 10) + (*str - '0');
		str++;
	}
	return (min * nb);
}
#include <unistd.h>
#include <strings.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{

	char *str1 = " +++-+1234ab567";
	char *str2 = " --+--+1234ab567";
	char *str3 = "+-+ -333rdd 0";
	char *str4 = "50 -d+-44qerf2";
	char *str5 = "+- 60fe33fw";
	char *str6 = "   -+-666gertg";
	char *array[]={str1, str2, str3, str4, str5, str6};

	for (int i = 0; i <= 5; i++)
	{
		printf("str:\t\"%s\"\nft_:\t%d\n", array[i], ft_atoi(array[i]));
		printf("lib:\t%d\n\n", atoi(array[i]));
	}
	return (0);
}

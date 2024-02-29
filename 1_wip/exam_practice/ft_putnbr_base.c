/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:14:14 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/29 15:03:59 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
/*
int	ft_putnbr_validate_base(char	*str)
{
	char	*copy;
	int		teller;

	teller = 0;
	while (*str != 0)
	{
		copy = str + 1;
		while (*copy != 0)
		{
			if (*str == *copy)
				return (0);
			copy++;
		}
		if (!((*str >= 48 && *str <= 57)
				|| (*str >= 65 && *str <= 90)
				|| (*str >= 97 && *str <= 122)))
			return (0);
		str++;
		teller ++;
	}
	if (teller == 0 || teller == 1)
		return (teller);
	else
		return (1);
}
*/
int		ft_strlen(char *s)
{
	int i = -1;
	while (s[++i])
	;
	return (i);
}
void	ft_putnbr_base(int nbr, char *base)
{
	int 	neg = 1;
	int		baselen = ft_strlen(base);
	if (baselen < 2)
		return ;
	if (nbr >= 0)
	{
		neg = 0;
		nbr = -nbr;
	}
	if (neg)
		write(1, "-", 1);
	if (nbr <= -baselen)
		ft_putnbr_base((-(nbr / baselen)), base);
	write(1, &base[-(nbr % baselen)], 1);
}

#include <strings.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int	nb = 3176468;
	char *str1 = "0123456789";
	char *str2 = "01";
	char *str3 = "0123456789ABCDEF";
	char *str4 = "0123AB2D";
	char *str5 = "01234567";
	char *str6 = "pone/yvif";
	
	char *array[]={str1, str2, str3, str4, str5, str6};

	for (int i = 0; i <= 5; i++)
	{
		printf("\n\nInput was: %d,\"%s\"\n", nb, array[i]);
		ft_putnbr_base(nb, array[i]);
	}
	return(0);
}

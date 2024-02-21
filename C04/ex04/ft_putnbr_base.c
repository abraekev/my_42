/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 09:42:32 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/19 08:40:59 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
De validate functie controleert op:
- geen dubbele waarden
- enkel nummers en kleine en grote letters toegelaten
- geen strings van lengte 1 of 0;   
*/

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
		return (0);
	else
		return (1);
}

/*
prep functie
- print een '-' indien getal negatief is
- berekent de lengte van de string en returnt die.
*/

int	ft_putnbr_prep(char *base, int is_pos)
{
	int	n;

	n = 0;
	if (!is_pos)
		write (1, "-", 1);
	while (*base != 0)
	{
		n++;
		base++;
	}
	return (n);
}

void	ft_putnbr_print(int nbr, char *base, int n)
{
	char	print;

	if (nbr <= -n)
	{
		ft_putnbr_print(nbr / n, base, n);
	}
	print = *(base - (nbr % n));
	write (1, &print, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{	
	int	n;
	int	is_pos;

	if (!ft_putnbr_validate_base(base))
		return ;
	if (nbr == 0)
		write(1, base, 1);
	else
	{
		if (nbr > 0)
		{
			is_pos = 1;
			nbr = -nbr;
		}
		else
			is_pos = 0;
		n = ft_putnbr_prep(base, is_pos);
		ft_putnbr_print(nbr, base, n);
	}
}

/*
#include <unistd.h>
#include <strings.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int	nb = -2147483648;
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
*/

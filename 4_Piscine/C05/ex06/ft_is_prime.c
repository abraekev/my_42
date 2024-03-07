/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 09:20:27 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/20 15:30:51 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
Create a function that returns 1 if the number given as a parameter is a prime
number, and 0 if it isn’t.
*/

int	ft_is_prime(int nb)
{
	int	i;

	if (nb <= 1)
		return (0);
	i = 2;
	while (i <= nb / i)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

/*
#include <stdio.h>

int	main()
{
	for (int n = -3 ; n <= 11; n++)
		printf("is %d een prime?   \t%s\n", n, ft_is_prime(n) ? "yes" : "no" );
	return (0);
}
*/

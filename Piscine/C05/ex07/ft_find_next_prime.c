/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 09:20:27 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/20 15:43:56 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Create a function that returns the next prime number
greater or equal to the number given as argument.
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

int	ft_find_next_prime(int nb)
{
	if (nb <= 2)
		return (2);
	if (!ft_is_prime(nb))
		return (ft_find_next_prime(nb + 1));
	else
		return (nb);
}

/*
#include <stdio.h>

int	main()
{
	for (int n = -3 ; n <= 11; n++)
		printf("Wat is de volgende prime >= %d?   \t%d\n", n, ft_find_next_prime(n));
	printf("Wat is de volgende prime >= %d?   \t%d\n", 2147483647,
	ft_find_next_prime(2147483647));
	return (0);
}
*/

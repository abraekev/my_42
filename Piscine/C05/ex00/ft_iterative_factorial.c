/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:33:19 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/15 15:57:19 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
• Create an iterated function that returns a number.
	This number is the result of a factorial operation
	based on the number given as a parameter.
• If the argument is not valid the function should return 0.
• Overflows must not be handled, the function return will be undefined.
*/

int	ft_iterative_factorial(int nb)
{
	int	result;

	result = nb;
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	while (nb > 1)
	{
		result = result * (nb -1);
		nb--;
	}
	return (result);
}

/*
#include <stdio.h>

int	main()
{
	int n;
	int x;

	n = 5;
	x = ft_iterative_factorial(n);
	printf("factorial %d: %d ", n, x);
	return (0);
}
*/

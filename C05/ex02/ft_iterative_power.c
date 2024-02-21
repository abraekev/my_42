/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:57:56 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/15 16:38:57 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	result;

	if (power == 0)
		return (1);
	if (power < 0 || (nb == 0 && power != 0))
		return (0);
	result = nb;
	while (--power > 0)
	{
		result = result * nb;
	}
	return (result);
}

/*
#include <stdio.h>

int	main()
{
	int n1 = 3;
	int n2 = -3;
	int n3 = 0;

	printf("%d tot de macht 3 is: %d\n", n1, ft_iterative_power(n1, 3));
	printf("%d tot de macht 3 is: %d\n", n2, ft_iterative_power(n2, 3));
	printf("%d tot de macht 3 is: %d\n", n3, ft_iterative_power(n3, 3));

	printf("3 tot de macht %d is: %d\n", n1, ft_iterative_power(3, n1));
	printf("3 tot de macht %d is: %d\n", n2, ft_iterative_power(3, n2));
	printf("3 tot de macht %d is: %d\n", n3, ft_iterative_power(3, n3));
	printf("0 tot de macht 0 is: %d\n", ft_iterative_power(0, 0));

	return (0);
}
*/

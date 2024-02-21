/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:57:56 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/20 14:42:02 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt_recur(int nb, int root)
{
	if (nb > 2147395600)
		return (0);
	if (root * root == nb)
		return (root);
	if (root * root < nb)
		return (ft_sqrt_recur(nb, root + 1));
	return (0);
}

int	ft_sqrt(int nb)
{
	return (ft_sqrt_recur(nb, 0));
}

/*
#include <stdio.h>

int	main()
{
	int n1 = 16;
	int n2 = 9;
	int n3 = 7;
	int n4 = 1;
	int n5 = 0;
	int n6 = -7;
	int n7 = 2147483647;

	printf("%d : %d\n", n1, ft_sqrt(n1));
	printf("%d : %d\n", n2, ft_sqrt(n2));
	printf("%d : %d\n", n3, ft_sqrt(n3));
	printf("%d : %d\n", n4, ft_sqrt(n4));
	printf("%d : %d\n", n5, ft_sqrt(n5));
	printf("%d : %d\n", n6, ft_sqrt(n6));
	printf("%d : %d\n", n7, ft_sqrt(n7));

	return (0);
}
*/

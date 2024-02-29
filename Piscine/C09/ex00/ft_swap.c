/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:47:48 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/09 10:28:18 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	x;

	x = *a;
	*a = *b;
	*b = x;
}

/*
int	main(void)
{
	int	nb1 = 42;
	int	nb2 = 123;
	int*	x = &nb1;
	int*	y = &nb2;

	printf("The value of nb1 is: %d\n", nb1);
        printf("The value of nb2 is: %d\n", nb2);
        printf("\n");
	ft_swap(x, y);
        printf("The value of nb1 is: %d\n", nb1);
        printf("The value of nb2 is: %d\n", nb2);

	return 0;
}
*/

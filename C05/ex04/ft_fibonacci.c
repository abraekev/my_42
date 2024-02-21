/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:57:56 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/16 08:36:14 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibo_recur(int index)
{
	if (index == 0)
		return (0);
	if (index == 1)
		return (1);
	return (ft_fibo_recur(index - 1) + ft_fibo_recur(index - 2));
}

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	return (ft_fibo_recur(index));
}

/*
#include <stdio.h>

int	main()
{
	int i[] = {0,1,2,3,4,5,6,7,8};

	for (int n = 0; n < 9; n++)
		printf("fibo index %d: %d\n", i[n], ft_fibonacci(i[n]));
	return (0);
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:46:28 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/28 14:59:01 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*res;

	res = malloc(sizeof(int) * length);
	if (!res)
		return (NULL);
	i = -1;
	while (++i < length)
	{
		res[i] = f(tab[i]);
	}
	return (res);
}
/*
#include <stdio.h>

int ft_mul(int a)
{
	return (a * 2);
}

int main (void)
{
	int	i;
	int *tab;
	int length;
	int *res;

	length = 4;
	tab = malloc(length * sizeof(int));
	i = 0;
	while (i < length)
	{
		tab[i] = i;
		i++;
	}
	res = ft_map(tab, length, &ft_mul);
	i = 0;
	while ( i < length)
	{
		printf( "%i", res[i]);
		i++;
	}
}
*/

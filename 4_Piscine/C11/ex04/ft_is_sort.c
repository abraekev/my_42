/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:35:12 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/28 16:19:59 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	j;

	i = -1;
	while (++i < length)
	{
		j = i;
		while (++j < length)
			if (f(tab[i], tab[j]) > 0)
				return (0);
		j = i;
		while (--j >= 0)
			if (f(tab[i], tab[j]) < 0)
				return (0);
	}
	return (1);
}
/*
#include <stdio.h>
#include <stdlib.h>

int        ft_tri(int a, int b)
{
    return (a - b);
}

int        main(void)
{
    static int    tabx[] = { 4, 5, 7, 9 };
    int            index;
    int            *tab;
    int            length;

    length = 4;

    printf("%d\n", ft_is_sort(tabx, length, &ft_tri));
}
*/

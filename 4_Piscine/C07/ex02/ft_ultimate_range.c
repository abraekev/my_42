/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:09:51 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/19 15:40:18 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*array;
	int	count;
	int	i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	count = (max - min);
	array = malloc(sizeof(int) * count);
	if (!array)
		return (-1);
	i = 0;
	while (i < count)
	{
		array[i] = min + i;
		i++;
	}
	*range = array;
	return (count);
}

/*
#include <stdio.h>

int	main(void)
{
	int	**range;
	int	min;
	int	max;
	int 	size;

	min = 7;
	max = 5;
	size = ft_ultimate_range(range, min, max);
	
	printf("\n%d\n", size);
	int i = -1;
	while (++i < 3)
	{
		printf("%d ",(*range)[i]);
	}
	return (0);
}
*/

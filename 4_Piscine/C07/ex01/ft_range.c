/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:09:51 by abraekev          #+#    #+#             */
/*   Updated: 2024/02/19 15:06:35 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*out;
	int	delta;
	int	i;

	if (min >= max)
		return (NULL);
	delta = max - min;
	out = malloc((sizeof(int) * delta));
	i = 0;
	while (i < delta)
	{
		out[i] = min;
		i++;
		min++;
	}
	return (out);
}

/*
#include <stdio.h>

int	main(void)
{
	
	int *a = ft_range(2, 5);

	int i = -1;
	while (++i < 8)
	{
		printf("%d ",a[i]);
	}
	return (0);
}
*/

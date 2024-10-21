/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 21:42:32 by abraekev          #+#    #+#             */
/*   Updated: 2024/10/21 13:54:05 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_ps *data)
{
	int	first;
	int	second;
	int	third;

	first = value(&data->a, 1);
	second = value(&data->a, 2);
	third = value(&data->a, 3);
	if (first > second && third > second && third > first)
		sa(data);
	else if (first > second && third > second && first > third)
		ra(data);
	else if (second > first && second > third && first > third)
		rra(data);
	else if (second > first && second > third && third > first)
	{
		sa(data);
		ra(data);
	}
	else if (first > second && second > third && first > third)
	{
		sa(data);
		rra(data);
	}
}

void	sort(t_ps *data)
{
	if (data->a.size <= 1 || is_sorted(data))
		return ;
	else if (data->a.size == 3)
		sort_three(data);
	else
	// sort data
}

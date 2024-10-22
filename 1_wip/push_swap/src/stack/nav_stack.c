/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nav_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 19:24:37 by abraekev          #+#    #+#             */
/*   Updated: 2024/10/22 14:25:52 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	next_down(t_stack *stack, int index)
{
	if (stack->size == 0)
		return (index);
	return ((index + 1) % stack->size);
}

int	next_up(t_stack *stack, int index)
{
	if (stack->size == 0)
		return (index);
	return ((index - 1 + stack->size) % stack->size);
}

int	value(t_stack *stack, int position)
{
	int	index;

	index = (stack->top + position - 1 + stack->size) % stack->size;
	return (stack->stack[index]);
}

int rank_max(t_stack *stack)
{
    int	rank;
	int	max_rank;
	int	max_value;
	
	rank = 1;
	max_rank = 0;
	max_value = 0;
	while (rank <= stack->size)
	{
		if (value(stack, rank) > max_value)
		{
			max_value = value(stack, rank);
			max_rank = rank;
		}
		rank++;
	}
	return (max_rank);
}
